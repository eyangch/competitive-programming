N = int(input())
good = 0
for i in range(1, 1000):
    si = str(i)
    if N % i == 0 and si.count('4') + si.count('7') == len(si):
        good = 1
print(["NO", "YES"][good])
