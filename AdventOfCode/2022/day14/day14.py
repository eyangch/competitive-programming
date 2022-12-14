grid = [[0] * 1000 for _ in range(1000)]

mxy = 0

while True:
	l = input()
	if l[0] == '~':
		break
	l = l.split(' -> ')
	px = -1
	py = -1
	for x in l:
		y = x.split(',')
		a = int(y[0])
		b = int(y[1])
		if px != -1:
			while px != a or py != b:
				#print(px)
				grid[px][py] = 1
				if px < a:
					px += 1
				if px > a:
					px -= 1
				if py < b:
					py += 1
				if py > b:
					py -= 1
		px = a
		py = b
		grid[a][b] = 1
		mxy = max(mxy, b)

for i in range(10):
	for j in range(494, 504):
		print(grid[j][i], end="")
	print()

def dest(x, y):
	if y + 1 >= 1000:
		return -1
	if grid[x][y+1] == 0:
		return 1
	if grid[x-1][y+1] == 0:
		return 2
	if grid[x+1][y+1] == 0:
		return 3
	return 0

def part1():
	ans1 = 0
	done = False
	while True:
		sx = 500
		sy = 0
		while True:
			c = dest(sx, sy)
			if c == -1:
				done = True
				break
			if c == 0:
				break
			if c == 1:
				sy += 1
			if c == 2:
				sy += 1
				sx -= 1
			if c == 3:
				sy += 1
				sx += 1
		if done:
			break
		grid[sx][sy] = 1
		ans1 += 1

	print(ans1)

def part2():
	for i in range(1000):
		grid[i][mxy+2] = 1
	ans2 = 0
	done = False
	while True:
		sx = 500
		sy = 0
		if grid[sx][sy] == 1:
			break
		while True:
			c = dest(sx, sy)
			if c == 0:
				break
			if c == 1:
				sy += 1
			if c == 2:
				sy += 1
				sx -= 1
			if c == 3:
				sy += 1
				sx += 1
		grid[sx][sy] = 1
		ans2 += 1

	print(ans2)

part2()