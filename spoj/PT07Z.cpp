#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb emplace_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(0);
const int N = 10005;
vector<int> graph[N];
bool vis[N] , vis1[N];
int dis[N] , dis1[N];
int32_t main(){
	fast;
	int n;
	cin >> n;
	
	for(int i=1 ; i<=n-1 ; i++)
	{
		int x,y;
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : graph[u])
		{
			if(!vis[v])
			{
				vis[v] = true;
				q.push(v);
				dis[v] = dis[u] + 1;
			}
		}
	}
	
	int maximum_dis = 0;
	int indx = 0;
	
	for(int i=1 ; i<=n ; i++)
	{
		maximum_dis = max(maximum_dis , dis[i]);
		if(maximum_dis == dis[i])
			indx = i;
	}
	
	queue<int> q1;
	q1.push(indx);
	vis1[indx] = true;
	while(!q1.empty())
	{
		int u = q1.front();
		q1.pop();
		for(auto v : graph[u])
		{
			if(!vis1[v])
			{
				vis1[v] = true;
				q1.push(v);
				dis1[v] = dis1[u] + 1;
			}
		}
	}
	int ans = *max_element(dis1 , dis1 + N);
	cout << ans;
}
 
 
 
