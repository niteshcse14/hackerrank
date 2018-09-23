#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >v[4];
ll calculate(pair<ll,ll> p,pair<ll,ll> q,ll n)
{
    ll dx,dy,total=0;
    if((p.first==0 && q.first==n)||(p.first==n && q.first==0)){
        dx=n;
        dy=p.second+q.second;
    }else if((p.second==0 && q.second==n)||(p.second==n && q.second==0)){
        dx=p.first+q.first;
        dy=n;
    }else{
        dx=abs(p.first-q.first);
        dy=abs(p.second-q.second);
    }
    return (dx+dy);
}
int main(){
 //  freopen("input.txt","r",stdin);

ll n,m,k;
cin>>n>>m>>k;
 if (k == 1) {
        cout << 0;
        return 0;
    }
for(ll i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    if(x==0){
        v[0].push_back(make_pair(x,y));
    }
    else if(y==5){
        v[1].push_back(make_pair(x,y));
    }
    else if(x==5){
        v[2].push_back(make_pair(x,y));
    }
    else if(y == 0) 
    {
    	v[3].push_back(make_pair(x,y));
    }

}
sort(v[0].begin(),v[0].end());
sort(v[1].begin(),v[1].end());
sort(v[2].rbegin(),v[2].rend());
sort(v[3].rbegin(),v[3].rend());

vector<pair< ll,ll> > graph;
graph.clear();

for(ll i=0;i<4;i++){
    for(ll j=0;j<v[i].size();j++){
        graph.push_back(v[i][j]);

    }
}
ll dist=INT_MAX;
for(int i = 0; i < m; i++)
{
	ll sum = 0, count = 0;
	//cout << "From " << graph[i].first << "  " << graph[i].second << "\n";
	for(int j = i; count < k - 1; j++, count++)
	{
		//cout << graph[j % m].first << "  " << graph[j % m].second << "      ";
		//cout << graph[(j + 1) % m].first << "  " << graph[(j + 1) % m].second << "\n";
		sum += calculate(graph[j % m], graph[(j + 1) % m], n);
        //cout << sum << " ";
	}
    printf("\n");
	cout << sum << "\n";
	dist = min(dist, sum);
}
cout << dist << "\n";
/*
for(ll i=0;i<graph.size();i++){
    ll temp=calculate(graph[i],graph[((i+k-1)%graph.size())],n);
   // cout<<"temp-"<<temp<<endl;
    ll act=min(temp,4*n-temp);
    dist=min(dist,act);
    //cout<<dist<<endl;
}
cout<<dist;
*/
return 0;}
