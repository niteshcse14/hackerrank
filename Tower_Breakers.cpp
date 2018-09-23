#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, M;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		if(M == 1 || N % 2 == 0)
		{
			printf("2\n");
		}
		else
		{
			printf("1\n");//, (M % 2 == 0) ? 1 : 2);
		}

	}
	return 0;
}