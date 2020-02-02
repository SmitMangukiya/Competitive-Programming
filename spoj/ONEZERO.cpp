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
     
    const int inf = 1e9;
    const int inf64 = 1e18;
    const int MOD = inf + 7;
    const ld PI = acos(-1.0);
    void solve()
    {
    	int n;
    	cin >> n;
    	
    	queue<pair<string,int>>q;
    	
    	q.push({"1" , 1 % n});
    	
    	while(!q.empty())
    	{
    		auto p = q.front();
    		q.pop();
    		
    		if(p.S == 0)
    		{
    			cout << p.F << "\n";
    			return;
    		}
    		
    		q.push({p.F + "0" , (p.S * 10)%n});
    		q.push({p.F + "1" , (p.S * 10 + 1)%n});
    	}
    }
    int32_t main(){
    	fast;
    	int t;
    	cin >> t;
    	while(t--)
    		solve();
    } 
