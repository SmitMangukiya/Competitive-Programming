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
 
string s;
int tot;
int dp[1005][5005];
int pos[1005];
 
int solve(int id , int sum)
{
	if(sum < 0) return INF64;
	if(id == s.length())    return (sum == 0 ? 0 : INF64);
 
	int ans = dp[id][sum];
	if(ans != -1)   return ans;
	ans = INF64;
	int cur = 0 , i = pos[id];
	while(cur <= sum && i < s.length())
	{
		cur = cur*10 + s[i] - '0';
		ans = min(ans , solve(i+1,sum-cur) + 1);
		i++;
	}
	return dp[id][sum] =ans;
}
int32_t main(){
	fast;
	cin >> s;
	for(int i=0 ; i<s.length() ; i++)
	{
		if(s[i] == '=')
		{
			tot = stol(s.substr(i+1));
			s = s.substr(0,i);
			break;
		}
	}
	pos[s.length() - 1] = s.length() - 1;
	for(int i=s.length() - 2 ; i>=0 ; i--)
		pos[i] = (s[i] == '0' ? pos[i+1] : i);
		
	memset(dp,-1,sizeof(dp));
	int ans = max(0LL , solve(0,tot)-1);
	cout << ans;
}
