sns = []

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
	cs = [(xp, yp), abs(xp - xb) + abs(yp - yb)]
	#ab.append((xb, yb))
	sns.append(cs)

ub = 4000000
#ub = 20

def ok(x, y):
	if x > ub or y > ub or x < 0 or y < 0:
		return False
	for s in sns:
		if abs(x - s[0][0]) + abs(y - s[0][1]) <= s[1]:
			return False
	return True

fx = -1
fy = -1

cnt = 0

for s in sns:
	print(s)
	x = s[0][0]
	y = s[0][1]
	d = s[1]
	for i in range(-d, d+1):
		cx = x + i
		ad = d - abs(i)
		cy1 = y+ad+1
		cy2 = y-ad-1
		if(ok(cx, cy1)):
			fx = cx
			fy = cy1
			cn
		if(ok(cx, cy2)):
			fx = cx
			fy = cy2
	for i in range(-d, d+1):
		cy = y + i
		ad = d - abs(i)
		cx1 = x+ad+1
		cx2 = x-ad-1
		if(ok(cx1, cy)):
			fx = cx1
			fy = cy
		if(ok(cx2, cy)):
			fx = cx2
			fy = cy

print(fx)
print(fy)
print(fx * 4000000 + fy)
