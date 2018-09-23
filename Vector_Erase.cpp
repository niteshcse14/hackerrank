#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > arr;
int n, a, b;
int main() {
	arr.clear();
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d", &arr[i]);
	}
	scanf("%d", &a);
	a--;
	arr.erase(arr.begin() + a);
	scanf("%d%d", &a, &b);
	a--;
	b--;
	arr.erase(arr.begin() + a, arr.begin() + b);
	n = arr.size();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}