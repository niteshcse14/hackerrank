#include <bits/stdc++.h>
using namespace std;
void mmul(int arr[4][4], int M[4][4])
{
	int C[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                C[i][j] += arr[i][k] * M[k][j];
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            arr[i][j] = C[i][j];
        }
    }
}
void power(int arr[4][4], int N)
{
	int M[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
	if(N == 0 || N == 1)
	{
		return;
	}
	power(arr, N / 2);
	mmul(arr, arr);
	if(N % 2 != 0)
	{
		mmul(arr, M);
	}
}
int rec(int N)
{
	int arr[4][4] = {{1, 1, 0, 2}, {1, 0, 0, 0}, {1, 0, 1, 0}, {0, 0, 1, 0}};
	if(N == 0)
	{
		return 0;
	}
	power(arr, N);
	return arr[0][0];
}
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cout << rec(N) << "\n";
	}
	return 0;
}
//Solve_the_Recurrence.cpp