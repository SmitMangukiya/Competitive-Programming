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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
 
const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = INF + 7;
const ld PI = acos(-1.0);
const int N = 105;
int dp[N][N][2];
 
int solve(int n , int k , int prev)
{
	if(n < 0 || k < 0)	return 0;
	if(n==1)	return (k==0);
	if(dp[n][k][prev] != -1)	return dp[n][k][prev];
 
	int ans = 0;
	if(prev == 0)
	{
		ans += solve(n-1,k,0) + solve(n-1,k,1);
	}
	else
	{
		ans += solve(n-1,k-1,1) + solve(n-1,k,0);
	}
	
	return dp[n][k][prev] = ans;
}
int32_t main(){
	fast;
	memset(dp,-1,sizeof(dp));
	int t;
	cin >> t;
	while(t--)
	{
		int id ,n ,k ;
		cin >> id >> n >> k;
		
		cout << id << " " << solve(n,k,0) + solve(n,k,1) << "\n";
	}
}
