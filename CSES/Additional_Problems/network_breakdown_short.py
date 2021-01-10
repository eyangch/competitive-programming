l=list
m=200000
def n():return map(int,input().split())
N,M,K=n()
c=[0]*M
f=[0]*K
r=[0]*K
p=list(range(N))
s=set()
z=N
def a(u):
    if u==p[u]:return u
    p[u]=a(p[u])
    return p[u]
def b(u,v):
    global z
    u=a(u)
    v=a(v)
    if u==v:return
    z-=1
    p[v]=u
for i in range(M):
    x=l(n())
    c[i]=m*(min(x)-1)+max(x)-1
for i in range(K):
    x=l(n())
    f[K-i-1]=m*(min(x)-1)+max(x)-1
    s.add(f[K-i-1])
for i in c:
    if i not in s:
        b(i//m,i%m)
for i in range(K):
    r[i]=z
    b(f[i]//m,f[i]%m)
for i in [0]*K:
    print(r.pop(),end=" ")
print()
