#include <bits/stdc++.h>
using namespace std;
int t;
char str[100005];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", str);
		int n = strlen(str);
		int sum = 0;
		for(int i = 1; i < n; ++i){
			int cnt = 0;
			int ii = i;
			for(int j = 0; j < n && ii < n; ++j){
				if(str[ii] != str[j]){
					break;
				}
				else{
					cnt++;
				}
				ii++;
			}
			//printf("%d\n", cnt);
			sum += cnt;
		}
		printf("%d\n", sum + n);
	}
	return 0;
}