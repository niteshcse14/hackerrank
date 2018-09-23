if __name__ == '__main__':
	n = int(raw_input())
	arr = [int (x) for x in raw_input().split()]
	arr.sort()
	flag = 0
	for i in range(n - 2, -1, -1) :
		#print(i, i + 1)
		if (arr[i] != arr[i + 1]) :
			print(arr[i])
			flag = 1
			break
	if (flag != 1) :
		print(arr[n - 1])