n = int(input())
x = set()
y = set()
for i in range(n):
	a, b = map(int, raw_input().split())
	x.add(a)
	y.add(b)
print min(len(x), len(y))
