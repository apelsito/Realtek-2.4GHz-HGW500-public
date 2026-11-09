import importlib.util
from pathlib import Path
import unittest

SPEC = importlib.util.spec_from_file_location("extract_comments", Path(__file__).resolve().parents[1] / "scripts" / "extract_original_comments.py")
MODULE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MODULE)


class CommentExtractionTests(unittest.TestCase):
    def test_literals_are_not_comments(self):
        text = 'char *url = "https://example/*path*/"; char c = \'/\'; /* real */ // tail\n'
        self.assertEqual([c[3] for c in MODULE.c_comments(text)], ["/* real */", "// tail"])

    def test_escaped_quote(self):
        text = '"escaped \\" // literal" /* actual */'
        self.assertEqual([c[3] for c in MODULE.c_comments(text)], ["/* actual */"])

    def test_line_continuation(self):
        text = '// first\\\ncontinued\nint x; /* second\nline */'
        self.assertEqual([c[3] for c in MODULE.c_comments(text)], ['// first\\\ncontinued', '/* second\nline */'])

    def test_hash_in_quoted_build_value(self):
        text = 'value = "#literal" # actual\n# next\n'
        self.assertEqual([c[3] for c in MODULE.hash_comments(text)], ['# actual', '# next'])

    def test_unterminated_comment_fails(self):
        with self.assertRaises(ValueError):
            list(MODULE.c_comments('/* incomplete'))


if __name__ == "__main__":
    unittest.main()
