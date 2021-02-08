def f():return list(map(int,input().split()))
n,x=f()
a=f()
t=z=0
for i in sorted(a):
    if i+t<=x:t+=i;z+=1
print(z)
