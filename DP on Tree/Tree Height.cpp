//https://www.codechef.com/problems/MCO16403
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define all(c) (c).begin(),(c).end()
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(nullptr);
const int N = 3e5 + 5;
vector<pair<int,int>> graph[N];
int n;
int sz[N] ,  ans[N] ;
void dfs(int node , int par)
{
	sz[node] = 1;
	for(auto v : graph[node])
	{
		if(v.F == par)    continue;
		dfs(v.F , node);
		sz[node] += sz[v.F];
		ans[node] += ans[v.F] + v.S*sz[v.F];
	}
}

void dfs1(int node , int par)
{
	for(auto v : graph[node])
	{
		if(v.F == par)  continue;
		ans[v.F] = ans[node] - v.S*( 2*sz[v.F] - n);
		dfs1(v.F , node);
	}
}

int32_t main(){
	fast;
	cin >> n;
	
	int x,y,z;
	f(i,0,n-1)
	{
		cin >> x >> y >> z;
		graph[x].pb({y,z});
		graph[y].pb({x,z});
	}
	
	dfs(1,-1);
	dfs1(1,-1);
	
	for(int i=1 ; i<=n ; i++)
		cout << ans[i] << " ";
}

