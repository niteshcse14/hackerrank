#include <bits/stdc++.h>
using namespace std;
const long long int P=1000000007;
void sol(){
    int n;
    scanf("%d",&n);
    long long x=0,y=1,z=0,ans=0;
    int a;
    for (int i=0;i<n;i++) {
        scanf("%d",&a);
        ans=ans*4+  //answer
        (y*12+8)%P*x%P+
        (y*12+8)%P*y%P*a+
        (y*2+1)%P*(y*2+1)%P*a;

        x=  x*4+    //from corner to all
            (z+a*2)%P*y%P+
            (z+a*3)%P*y%P*2+
            z*2+a*3;

        y=  y*4+2;  // number of nodes

        z=  z*2+a*3;//diameter

        ans%=P;
        x%=P;
        y%=P;
        z%=P;
    }
    cout<<ans<<"\n";
}

int main() {
    sol();
    return 0;
}