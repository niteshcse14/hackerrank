#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ll long long
int main()
{
	/*
	vector<ll> arr;
	arr.push_back(0);
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 0;
	arr[4] = 4;
	for(int i = 1; i<= 4; i++)
	{
		for(int j = i + 4; j < MAX; j += 4)
		{
			if(i == 1)
			{
				arr[j] = 1;
			}
			else if(i == 2 || i == 4)
			{
				arr[j] = arr[j -  4] + 4;
			}
			else if(i == 3)
			{
				arr[j] = 0;
			}
		}
	}
	*/
	/*
	for(int i = 0; i < 50; i++)
	{
		printf("%d   %d\n", i, arr[i]);
	}
	printf("\n");
	*/
	ll Q, data, L, R, sum;
	scanf("%lld", &Q);
	while(Q--)
	{
		sum = 0;
		scanf("%lld %lld", &L, &R);
		//L = 0;
		//R = 30;
		for(ll i = L; i <= R; )
		{
			if(i % 4 == 0)
			{
				ll total = (R - i + 1) / 8;
				if(total > 0)
				{
					i = i + 8 * total;
					continue;
				}
			}
			if(i % 4 == 0)
			{
				data = i;
			}
			else if(i % 2 == 0)
			{
				data = i + 1;
			}
			else if((i - 1) % 4 == 0)
			{
				data = 1;
			}
			else
			{
				data = 0;
			}
			//printf("%lld    %lld\n", i, data);
			sum ^= data;
			i++;
		}
		//printf("\n");
		printf("%lld\n", sum);
	}
	return 0;
}
/*
0   0
1   1
2   3
3   0
4   4
5   1
6   7
7   0
8   8
9   1
10   11
11   0
12   12
13   1
14   15
15   0
16   16
17   1
18   19
19   0
20   20
21   1
22   23
23   0
24   24
25   1
26   27
27   0
28   28
29   1
30   31
31   0
32   32
33   1
34   35
35   0
36   36
37   1
38   39
39   0
40   40
41   1
42   43
43   0
44   44
45   1
46   47
47   0
48   48
49   1
*/