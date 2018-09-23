#include <iostream>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t-->0) {
		cin>>n;
		int se[n][2];
		int max=0,min=999;
		for(int i=0;i<n;i++){
			cin>>se[i][0]>>se[i][1];
			if(se[i][0]<min)
				min=se[i][0];
		}
		int count;
		count=n;
		//cout<<count;
		for(int i=0;i<n;i++){
			//cout<<se[i][1]<<endl;
			if(se[i][1]>=min)
			count--;
		}
		cout<<count;
	}
}