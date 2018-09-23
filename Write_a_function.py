def is_leap(year):
	#print(year/4,' ',year//100)
	if year%400==0:
		return True
	return False
year=int(input())
print(is_leap(year))