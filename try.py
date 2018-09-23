def cmp_fun() :
	return cmp_fun
if __name__ == '__main__' :
	n = (int)(input())
	inp = []
	for i in range(n) :
		tmp = list(map(int, input().split()))
		inp.append(tmp)
	#inp.sort(sort(sort_function, cmp = cmp_fun))
	for i in range(len(inp)) :
		for j in range(len(inp[i])) :
			print(j, end = ' ')
		print()