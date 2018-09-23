#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int isPrime[MAXN];
int arrA[MAXN];
int arrB[MAXN];
int ans[MAXN];
int divisorA[MAXN];
int divisorB[MAXN];
int ANS, N, T, high;
int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &arrA[i]);
	}
	for(int i = 1; i <= N; ++i){
		scanf("%d", &arrB[i]);
	}
	for(int i = 1; i <= N; ++i){
		ans[arrA[i]]++;
	}
	for(int i = 1; i < MAXN; ++i){
		for(int j = i; j < MAXN; j += i){
			if(ans[j]){
				divisorA[i] = max(divisorA[i], j);
			}
		}
	}
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= N; ++i){
		ans[arrB[i]]++;
	}
	for(int i = 1; i < MAXN; ++i){
		for(int j = i; j < MAXN; j += i){
			if(ans[j]){
				divisorB[i] = max(divisorB[i], j);
			}
		}
	}
	for(int i = 1; i < MAXN; ++i){
		if(divisorA[i] && divisorB[i]){
			ANS = i;
		}
	}
	printf("%d %d\n", divisorA[ANS], divisorB[ANS]);
	return 0;
}