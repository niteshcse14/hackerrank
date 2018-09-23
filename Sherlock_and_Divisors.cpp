#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	vector<int> vect(1000001, 1);
    for (int i = 2; i * i < vect.size(); ++i)
    {
        if (vect[i])
        {
            for (int j = i * i; j < vect.size(); j += i) 
            {
                vect[j] = 0;
            }
        }
    }
    int l = 1, r = 1000000;
    //cin >> l >> r;
    vector<int> prime(r - l + 1, 1);
    if (l == 1) 
    {
        prime[0] = 0;
    }
    for (int i = 2; i < vect.size(); ++i) 
    {
        if (vect[i]) 
        {
            for (int j = max(i, (l + i - 1) / i * i); j <= r; j += i) 
            {
                if(i != j)
                {
                	prime[j - l] = 0;
                }
            }
        }
    }
    for(int i = 2; i < 100; i++)
    {
    	if(prime[i])
    	{
    		cout << i + 1 << "  ";
    	}
    }
    printf("\n");
    /*
	vector<int> mark(1000001, 1);
	int k = 0;
	ll T, N, ans;
	ll arr[1000001];
	for(int i = 2; i * i <= 1000001; i++)
	{
		if(mark[i])
		{
			for(int j = 2 * i; j < 1000001; j += i)
			{
				mark[j] = 0;
			}
		}
	}
	*?
	/*
	for(int i = 3; i < 1000001; i++)
	{
		if(mark[i])
		{
			arr[k++] = i;
		}
	}
	*/
	/*
	ll low = 100;
	ll heigh = 100001;
	vector<int> prime(heigh - low + 1, 1);
	for(int i = 2; i < mark.size(); i++)
	{
		if(mark[i])
		{
			for(int j = (i + low - 1) / i * i; j < heigh; j += i)
			{
				if(i != j)
				{
					prime[j - low] = 1;
				}
			}
		}
	}
	for(int i = 1; i < 100; i++)
	{
		if(prime[i])
		{
			cout << i << " ";
		}
	}
	printf("\n");
	*/
	/*
	cin >> T;
	while(T--)
	{
		ans = 1;
		cin >> N;
		if(N % 2 == 0)
		{
			int count = 0;
			while(N % 2 == 0)
			{
				N = N / 2;
				count++;
				cout << "factor 2\n";
			}
			ll ans = count;
			for(int i = 0; i < k; i++)
			{
				count = 0;
				if(N % arr[i] == 0)
				{
					while(N % arr[i] == 0)
					{
						N = N / arr[i];
						count++;
						cout << "factor " << arr[i] << "\n";
					}
					ans *= (count + 1);
				}
				if(N == 1)
				{
					break;
				}
			}
			cout << N << "\n";
			cout << ans << "\n";
		}
		else
		{
			cout << "0\n";
		}
	}

	*/
	return 0;
}
//Sherlock_and_Divisors.cpp