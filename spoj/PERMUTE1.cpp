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
    const int N = 13;
    int n,k,dp[1<<N][N][100];
    int solve(int mask , int id , int inv)
    {
    	if(inv < 0) return 0;
    	if(id == n) return (inv==0);
    	int ans = dp[mask][id][inv];
    	if(ans != -1)   return ans;
    	ans = 0;
    	
    	int cnt = 0;
    	for(int i=0 ; i<n ;i++)
    	{
    		if((mask & 1<<i) == 0)
    		{
    			ans += solve(mask | (1<<i) , id+1 , inv - cnt);
    		}
    		else
    			cnt++;
    	}
    	
    	return dp[mask][id][inv] = ans;
    }
    int32_t main(){
    	fast;
    	int t;
    	cin >> t;
    	while(t--)
    	{
    		memset(dp,-1,sizeof(dp));
    		cin >> n >> k;
    		int ans = 0;
    		for(int i=0 ; i<n ; i++)
    		{
    			ans += solve(1<<i , 1 , k);
    		}
    		cout << ans << "\n";
    	}
    }
     
     
