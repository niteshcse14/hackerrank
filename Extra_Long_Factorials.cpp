#include <bits/stdc++.h>
using namespace std;
int multiply(int x, int arr[], int res_size)
{
	int carry = 0;
	for(int i = 0; i < res_size; i++)
	{
		int prod = arr[i] * x + carry;
		arr[i] = prod % 10;
		carry = prod / 10;
	}
	while(carry)
	{
		arr[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}
int main()
{
	int N, MAX_SIZE = 1000006, res_size = 1;
	cin>>N;
	int arr[MAX_SIZE] = { 0 };
	arr[0] = 1;
	for(int i = 2; i <= N; i++)
	{
		res_size = multiply(i, arr, res_size);
	}
	for(int i = res_size - 1; i >= 0; i--)
	{
		cout<<arr[i];
	}
	printf("\n");
	return 0;
}
//Extra_Long_Factorials.cpp