n = input()
mx = [0]*110
my = [0]*110
for i in range(n):
	x, y = map(int, raw_input().split())
	mx[x] = my[y] = 1
ansx = 0
ansy = 0
for i in range(0,101):
	if(mx[i] == 1):
		ansx+=1
	if(my[i] == 1):
		ansy+=1
ans = min(ansx, ansy)
print ans
		
	
