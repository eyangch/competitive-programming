ans = 0
mp = 1

def comp(a, b):
	if type(a) == int:
		a = [a]
	if type(b) == int:
		b = [b]
	if len(a) == 1 and len(b) == 1 and type(a[0]) == int and type(b[0]) == int:
		if a[0] == b[0]:
			return 0
		if a[0] > b[0]:
			return 1
		if a[0] < b[0]:
			return -1
	if len(a) == 0 and len(b) == 0:
		return 0
	if len(a) == 0:
		return -1
	if len(b) == 0:
		return 1
	y = comp(a[0], b[0])
	if y == 0:
		return comp(a[1:], b[1:])
	return y

arr = [[[2]], [[6]]]

while True:
	l1 = input()
	l2 = input()
	if l1[0] == '~':
		break;
	a = eval(l1)
	b = eval(l2)
	arr.append(a)
	arr.append(b)
	x = comp(a, b)
	#print(x)
	if x == -1:
		ans += mp
	input()
	mp += 1

from functools import cmp_to_key
arr.sort(key=cmp_to_key(comp))

ans2 = 1

for i in range(len(arr)):
	if arr[i] == [[2]] or arr[i] == [[6]]:
		ans2 *= (i+1)

print(ans)
print(ans2)