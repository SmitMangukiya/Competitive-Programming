// https://www.spoj.com/problems/PT07X/
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
const int N = 1e5 + 5;
vector<int> graph[N];
int n , dp[N][2];
void dfs(int u , int par)
{
	int taken = 1;
	int ntaken = 0;
 
	for(auto v : graph[u])
	{
		if(v == par)    continue;
		dfs(v,u);
		taken += min(dp[v][0] , dp[v][1]);
		ntaken += dp[v][1];
	}
	
	dp[u][0] = ntaken;
	dp[u][1] = taken;
}
int32_t main(){
	fast;
	cin >> n;
	
	int x,y;
	f(i,0,n-1)
	{
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	
	dfs(1,-1);
	cout << min(dp[1][0] , dp[1][1]);
}
