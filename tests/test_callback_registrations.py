"""Callback analysis parsing edges that prevent false registration counts."""
from pathlib import Path
import sys
import tempfile
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'scripts'))
from audit_callback_registrations import call_args, comment_mask, function_value_uses
from audit_driver_ops import Elf


class CallbackTests(unittest.TestCase):
    def test_nested_and_quoted_arguments(self):
        text='f((a + g(1,2)), "literal,comma", callback)'
        args,end=call_args(text, text.index('('))
        self.assertEqual(args, ['(a + g(1,2))', '"literal,comma"', 'callback'])
        self.assertEqual(end,len(text))

    def test_comment_mask_preserves_source_lines(self):
        text='/* callback\nphantom */\nreal(); // another()'
        masked=comment_mask(text)
        self.assertEqual(masked.count('\n'),text.count('\n'))
        self.assertNotIn('phantom',masked)

    def test_function_calls_do_not_count_as_values(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory);p=root/'test.c'
            p.write_text('void callback(void) {}\nvoid call(void) { callback(); }\nstruct ops o={\n.run=callback,\n};\n')
            uses=function_value_uses(root,[('module',p)],['callback'],[])
            self.assertEqual(len(uses),1)
            self.assertEqual(uses[0]['classification'],'STATIC_TABLE_INITIALIZER')

    def test_param_ops_is_undefined_data_object(self):
        e=object.__new__(Elf);e.sections=[dict(name='')]
        e.syms=[dict(name='param_ops_bool',section=0,value=0,type=0)]
        result=e.target(dict(symbol=0,addend=0,type=4))
        self.assertEqual(result['functions'],[])
        self.assertEqual(result['import_kind'],'DATA_OBJECT')


if __name__=='__main__':
    unittest.main()
