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
const int N = 20;

int n,k,a[2*N],dp[2*N][N],x;
int solve(int id , int close)
{
	if(2*close > id)    return 0;
	if(id == 2*n)   return (close == n);
	int ans = dp[id][close];
	if(ans != -1)   return ans;
	ans = 0;
	if(a[id+1] == 1)
		ans = solve(id+1,close);
	else
		ans = solve(id+1,close) + solve(id+1, close+1);
	return dp[id][close] = ans;
}
int32_t main(){
	fast;
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		memset(a,0,sizeof(a));
		cin >> n >> k;
		for(int i=1 ; i<=k ; i++)   cin >> x ,a[x] = 1 ;
		int ans = solve(1,0);
		cout << ans << "\n";
	}
}
