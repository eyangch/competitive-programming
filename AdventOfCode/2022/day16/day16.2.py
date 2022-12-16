from collections import deque

D = {}
aid = 0
nid = 0

while True:
	l = input()
	if l[0] == '~':
		break
	l = l.split(' ')
	vn = l[1]
	rate = int(l[4][5:-1])
	caid = -1
	if rate > 0:
		caid = aid
		aid += 1
	cnid = nid
	nid += 1
	ld = []
	for i in range(9, len(l)):
		s = l[i]
		if i != len(l)-1:
			s = s[:-1]
		ld.append(s)
	D[vn] = (rate, ld, cnid, caid)

dp = [[-1] * 100 for _ in range(pow(2, 18))]

def bfs(vx, sx, tx):
	Q = deque()
	Q.append((vx, sx, tx, 0))
	while(len(Q) > 0):
		cq = Q.popleft()
		v = cq[0]
		s = cq[1]
		t = cq[2]
		id1 = cq[3]
		z = D[v][2]
		w = D[v][3]
		if dp[id1][z] >= s:
			continue
		dp[id1][z] = s
		if t == 26:
			continue
		f = D[v][0]
		c = D[v][1]
		if f > 0 and (id1 & (1<<w)) == 0:
			t2 = t + 1
			s2 = s + f * (26 - t2)
			Q.append((v, s2, t2, id1 | (1<<w)))
		for x in c:
			Q.append((x, s, t+1, id1))

bfs('AA', 0, 0)

ans2 = 0

dp2 = [0] * (1<<16)
for i in range(1<<16):
	for j in range(100):
		dp2[i] = max(dp2[i], dp[i][j])

for i in range(1<<16):
	j = i
	while j > 0:
		ni = ((~i) & ((1<<16)-1))
		j = (j-1) & i
		ans2 = max(ans2, dp2[ni] + dp2[j])

print(ans2)