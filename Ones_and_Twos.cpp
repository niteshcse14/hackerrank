#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <cassert>
    
using namespace std;
    
const int P = 1000000007;
const int maxN = 1100;
int dp[maxN][maxN], s[maxN][maxN];
int main() {
	int B = 5;
    for (int j = 0; j <= B; j++) dp[0][j] = dp[j][0] = 1;
	for (int i = 1; i <= B; i++) {
    	for (int j = 1; j <= B; j++) {
        	dp[i][j] = (i>j? dp[i-j][j-1] : 0) + dp[i][j - 1];
        }
    }
    for (int i = 1; i <= B; i++) {
    	for (int j = 0; j <= B; j++) {
        	printf("%d  ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
    