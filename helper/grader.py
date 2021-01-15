import sys
from timeit import timeit
import subprocess
import platform
from zipfile import ZipFile
import time
import resource

def bad():
    print("USAGE: {} <test data zip> <source file>".format(sys.argv[0]))
    print("Supported languages: C++11, Java")
    sys.exit(1)

if platform.system() == "Windows":
    print("Currently, Windows is unsupported.")

if len(sys.argv) != 3:
    bad()

zipf = sys.argv[1]
runf = sys.argv[2]

ftype = runf.split('.')[-1]

c_command = None
r_command = None

if ftype == "cpp" or ftype == "cxx" or ftype == "cc" or ftype == "C":
    c_command = ["g++", "-std=c++11", "-lm", "-O2", "-fsanitize=undefined", runf]
    r_command = ["./a.out"]
elif ftype == "java":
    c_command = ["javac", runf]
    r_command = ["java", runf[:-5]]
else:
    bad()

print(c_command)
print(r_command)

c_time = round(timeit(stmt="subprocess.Popen({}).communicate()".format(c_command), globals=globals(), number=1)*1000, 3)
time.sleep(0.01)
print("Compile time: {}ms".format(c_time))

with ZipFile(zipf) as z:
    tc = len(z.infolist()) // 2
    for i in range(tc):
        with z.open("{}.in".format(i+1)) as f:
            with open("grader.in", "wb") as wf:
                wf.write(f.read())
            r_time = round(timeit(stmt="subprocess.Popen({}).communicate()".format(r_command), globals=globals(), number=1)*1000, 3)
            time.sleep(0.01)
            c_bytes = None
            u_bytes = None
            with z.open("{}.out".format(i+1)) as cf:
                c_bytes = cf.read()
            with open("grader.out", "rb") as uf:
                u_bytes = uf.read()
            if c_bytes == u_bytes:
                print("AC")
            else:
                print("WA")
                sys.exit(0)
            print("Time: {}ms".format(r_time))

