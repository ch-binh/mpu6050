import ctypes
import os
import timeit

# === Load DLL ===
lib_path = os.path.abspath("bin/libadvm.dll")
lib = ctypes.CDLL(lib_path)

# Khai báo đúng kiểu float
lib.advm_add.argtypes = [ctypes.c_float, ctypes.c_float]
lib.advm_add.restype = ctypes.c_float

# === Test giá trị ===
a = ctypes.c_float(42)
b = ctypes.c_float(-19)

result = lib.advm_add(a, b)
result2 = 42.0 + (-19.0)

print(f"{a.value} + {b.value} = {result:.6f}  (from DLL)")
print(f"{a.value} + {b.value} = {result2:.6f}  (Python native)")

# === Benchmark ===

# Gọi DLL 1 triệu lần
dll_time = timeit.timeit(
    stmt="lib.advm_add(a, b)",
    setup="from __main__ import lib, a, b",
    number=1_000_000,
)

# Gọi native Python float 1 triệu lần
py_time = timeit.timeit(
    stmt="a.value + b.value",
    setup="from __main__ import a, b",
    number=1_000_000,
)

print(f"DLL time   : {dll_time:.4f} sec")
print(f"Python time: {py_time:.4f} sec")
