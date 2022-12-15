sns = []

tgy = 2000000
ab = []

while True:
	l = input()
	if(l[0] == '~'):
		break
	l = l.split(' ')
	xp = int(l[2][2:-1])
	yp = int(l[3][2:-1])
	xb = int(l[8][2:-1])
	yb = int(l[9][2:])
	#print(f"{xp} {yp} {xb} {yb}")
	cs = [(xp+50000000, yp), abs(xp - xb) + abs(yp - yb)]
	ab.append((xb+50000000, yb))
	sns.append(cs)

bd = [0] * 500000000

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for s in sns:
	x = s[0][0]
	y = s[0][1]
	d = s[1]
	d -= abs(tgy - y)
	#print(f"{x} {y} {d}")
	for i in range(x-d, x+d+1):
		if (i, tgy) in ab:
			continue
		bd[i] = 1

ans1 = sum(bd)

print(ans1)