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
int n,k;
int dp[20][10];

int solve(int id , int prev)
{
	if(id == n) return 1;
	int ans = dp[id][prev];
	
	if(ans != -1)   return ans;
	
	int l = 0;
	if(id == 0) l = 1;
	
	ans = 0;
	for(int i=l ; i<=k-1 ; i++)
	{
		if(i == 0 && prev == 0)
			continue;
		ans += solve(id + 1 , i);
	}
	dp[id][prev] = ans;
	return ans;
}
int32_t main(){
	fast;
	cin >> n >> k;
	
	memset(dp , -1 , sizeof(dp));
	
	cout << solve(0,0);
}

