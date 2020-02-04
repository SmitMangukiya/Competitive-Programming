//https://www.codechef.com/problems/FAMTREE
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
vector<int> graph[N];
int n,p,root;
int a[N] , dp[N][2] , ans = 0;

void dfs(int node , int par)
{
	dp[node][0] = a[node];
	dp[node][1] = a[node];
	
	for(auto v : graph[node])
	{
		if(v == par)    continue;
		dfs(v , node);
		ans = max(ans , abs(a[node] - dp[v][0]));
		ans = max(ans , abs(a[node] - dp[v][1]));
		
		dp[node][0] = max(dp[node][0] , dp[v][0]);
		dp[node][1] = min(dp[node][1] , dp[v][1]);
	}
}
int32_t main(){
	fast;
	cin >> n;
	
	f(i,1,n+1)  cin >> a[i];
	f(i,1,n+1)
	{
		cin >> p;
		if(p != -1)
		{
			graph[i].pb(p);
			graph[p].pb(i);
		}
		else
			root = i;
	}
	
	dfs(root , -1);
	cout << ans;
}
