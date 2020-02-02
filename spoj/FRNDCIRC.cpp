#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb emplace_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(0);
const int N = 1e5 + 5;
vector<int> id(N,0);
vector<int> sz(N,0);
void pre(){
	id.clear();
	sz.clear();
	id.resize(N,0);
	sz.resize(N,0);
	for(int i= 0 ; i<N ; i++) id[i] = i , sz[i] = 1;
}
 
int root(int i){
 
	while(i != id[i])	id[i] = id[id[i]] , i = id[i];
	return i;
}
 
void uni(int a, int b){
	int ra = root(a);
	int rb = root(b);
	if(ra == rb)	return;
	if(sz[ra] < sz[rb]) swap(ra,rb);
	id[rb] = ra , sz[ra] += sz[rb];
}
 
 
int32_t main(){
	fast;
	int t;
	cin >> t;
	while(t--)
	{
		pre();
		map<string,int>m;
		int n , cur = 1;
		cin >> n;
		while(n--)
		{
			string a,b;
			cin >> a >> b;
			if(m[a] == 0)   m[a] = cur++;
			if(m[b] == 0)   m[b] = cur++;
			uni(m[a] , m[b]);
			cout << sz[root(m[a])] << "\n";
		}
	}
}
 
