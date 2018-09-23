#include<stdio.h>
int A,B,C;
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int solve(){
    if(C>=A+B) { printf("1/1\n"); return; }
    if(B>A) swap(A,B);
    int num,den=2*A*B,g;
    num = (C<=B)? C*C:((C<=A) ? B*(2*C-B) : 2*A*B-(A+B-C)*(A+B-C));
    g=gcd(num,den);
    printf("%d/%d\n",num/g,den/g);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&A,&B,&C);
        solve();
    }
    return 0;
}