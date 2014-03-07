from sys import stdin, stdout
n = int(stdin.readline())
#a = [int(x) for x in raw_input().split(' ')]
#b = [int(x) for x in raw_input().split(' ')]
a = map(int, stdin.readline().split(' '))
b = map(int, stdin.readline().split(' '))
ans = 0
for i in range(n):
	if b[i] == 1 or a[i]*2 < b[i]:
		ans-=1
	else :
		ans += (b[i]/2) * (b[i] - b[i]/2)
stdout.write(str(ans))
#print ans
