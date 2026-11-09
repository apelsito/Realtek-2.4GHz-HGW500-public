"""Focused offline tests for ELF callback relocation and ABI conditional edges."""
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'scripts'))
from audit_driver_ops import Elf, pointer_fields, rate_fields, table


class OpsTests(unittest.TestCase):
    def test_conditional_layout_omits_disabled_pm(self):
        header = '''struct sample_ops {
        void (*tx)(void);
        #ifdef CONFIG_PM
        void (*suspend)(void);
        #endif
        #if IS_ENABLED(CONFIG_IPV6)
        void (*ipv6)(void);
        #endif
        };'''
        self.assertEqual(pointer_fields(header, 'sample_ops', {'CONFIG_IPV6': True}), ['tx', 'ipv6'])

    def test_unsupported_abi_condition_refused(self):
        with self.assertRaises(ValueError):
            pointer_fields('struct x {\n#if CONFIG_X && CONFIG_Y\nvoid (*x)(void);\n#endif\n};', 'x')

    def test_comments_never_create_fields(self):
        self.assertEqual(pointer_fields('struct x { /* void (*phantom)(void); */ void (*real)(void); };', 'x'), ['real'])

    def fixture(self):
        elf = object.__new__(Elf)
        elf.sections = [dict(name=''), dict(name='.data', data=bytes(12)), dict(name='.text', data=bytes(24))]
        elf.byname = {s['name']: s for s in elf.sections}
        elf.syms = [dict(name='', section=2, value=0, type=3),
                    dict(name='callback', section=2, value=16, size=8, type=2),
                    dict(name='imported_op', section=0, value=0, size=0, type=0)]
        elf.relas = [dict(section='.data', offset=0, symbol=0, addend=16, type=4),
                     dict(section='.data', offset=4, symbol=2, addend=0, type=4)]
        return elf, dict(name='ops', section=1, value=0, size=12)

    def test_section_relocation_recovers_local_callback(self):
        elf, symbol = self.fixture()
        result = table(elf, symbol, ['local', 'imported', 'unused'])
        self.assertEqual(result['slots'][0]['relocations'][0]['functions'], ['callback'])
        self.assertEqual(result['populated_callback_slots'], 2)

    def test_undefined_function_import_and_true_null_distinct(self):
        elf, symbol = self.fixture()
        result = table(elf, symbol, ['local', 'imported', 'unused'])
        self.assertTrue(result['slots'][1]['relocations'][0]['imported'])
        self.assertEqual(result['slots'][2]['classification'], 'NULL')

    def test_layout_mismatch_refused(self):
        elf, symbol = self.fixture()
        with self.assertRaises(ValueError):
            table(elf, symbol, ['too_short'])

    def test_rate_mixed_layout_retains_scalar_slots(self):
        header = 'struct rate_control_ops { unsigned long capa; const char *name; void *(*alloc)(void); };'
        self.assertEqual(rate_fields(header, {}), ['capa', 'name', 'alloc'])


if __name__ == '__main__':
    unittest.main()
