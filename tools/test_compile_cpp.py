import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
COMPILER = ROOT / "tools/gcc_cpp/cc1plus"


@unittest.skipUnless(COMPILER.is_file(), "run tools/setup_gcc_cpp.sh for C++ integration tests")
class CppCompilerTests(unittest.TestCase):
    def compile(self, source, extra_flags=()):
        with tempfile.TemporaryDirectory() as directory:
            source_path = Path(directory) / "probe.cpp"
            object_path = Path(directory) / "probe.o"
            source_path.write_text(source)
            result = subprocess.run(
                [sys.executable, str(ROOT / "tools/compile_agbcc.py"), str(source_path),
                 str(object_path), "-O2", "-mthumb-interwork", "-fno-exceptions",
                 "-fno-rtti", *extra_flags],
                capture_output=True,
            )
            return result, object_path.read_bytes() if object_path.exists() else b""

    def test_cpp_preprocessing_overloads_and_templates(self):
        result, obj = self.compile("""#ifndef __cplusplus
#error C++ preprocessing required
#endif
template<class T> T twice(T value) { return value + value; }
int probe(int value) { return twice(value); }
int probe(int first, int second) { return first + second; }
""")
        self.assertEqual(result.returncode, 0, result.stderr.decode())
        self.assertTrue(obj.startswith(b"\x7fELF"))
        self.assertIn(b"probe__Fi\0", obj)
        self.assertIn(b"probe__Fii\0", obj)

    def test_cpp_rejects_c_implicit_pointer_conversion(self):
        result, obj = self.compile("int *probe(void *value) { return value; }\n")
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(obj, b"")

    def test_cpp_cannot_fall_back_to_old_c_compiler(self):
        result, obj = self.compile("int probe() { return 0; }\n", ["--old-agbcc"])
        self.assertNotEqual(result.returncode, 0)
        self.assertIn(b"--old-agbcc does not support C++", result.stderr)
        self.assertEqual(obj, b"")


if __name__ == "__main__":
    unittest.main()
