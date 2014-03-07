from sys import stdin, stdout
tree = [([0]*100010) for i in range(11)]
a = [0] * 100010
def lowbit(x):
	return x&(-x)
def myadd(now, i, val, n):
	while i <= n:
		#print now, i
		tree[now][i] += val
		i = i + lowbit(i)
		
def mysum(now, n):
	sumt = 0
	nn = n
	while nn > 0:
		sumt += tree[now][nn]
		nn = nn - lowbit(nn)
	return sumt


def main():
	#n, k, w = map(int, raw_input().split())
	n, k, w = map(int, stdin.readline().split(' '))
	#s = raw_input()
	s = stdin.readline()
	for i in range(1,1+n):
		a[i] = 1 if s[i-1]=='1' else 0
		#print i, a[i]
	for i in range(k):
		j = i
		while j <= n:
			if(a[j] == 1):
				myadd(i,j,1,n)
			j+=k
	for j in range(1,n+1):
		if(a[j] == 1):
			myadd(k,j,1,n)
	
	for wt in range(w):
		ans = 0
		l, r = map(int, raw_input().split())
		kk = (l+k-1)%k
		#print "kk = " + str(kk)
		ans = mysum(k,r) - mysum(k,l-1) - 2*(mysum(kk,r) - mysum(kk,l-1)) + (r-l+1)/k
		#print mysum(k,r), mysum(k,l-1), mysum(kk,r), mysum(kk,l-1), (r-l+1)/k
		#print ans
		strt = str(ans) + '\n'
		stdout.write(strt)
main()
