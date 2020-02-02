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
    bool valid(int x , int y)
    {
    	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
    }
    void solve()
    {
    	string a,b;
    	cin >> a >> b;
    	
    	int x0 , y0 , x1 , y1;
    	
    	x0 = a[0] - 'a' + 1;
    	y0 = a[1] - '0';
    	x1 = b[0] - 'a' + 1;
    	y1 = b[1] - '0';
    	
    	queue<pair<int,pair<int,int>>>q;
    	map<pair<int,int> , int> vis;
    	q.push({0 , {x0 , y0}});
    	while(!q.empty())
    	{
    		auto p = q.front();
    		vis[p.S] = 1;
    		q.pop();
    		
    		if(p.S.F == x1 && p.S.S == y1)
    		{
    			cout << p.F << "\n";
    			return;
    		}
    		
    		for(auto i : {-2 , -1 , 1, 2})
    		{
    			for(auto j : {-2 , -1 , 1, 2})
    			{
    				if(abs(i) != abs(j) && valid(p.S.F +i , p.S.S +j) && vis[{p.S.F + i , p.S.S + j}] == 0)
    				{
    					q.push({p.F + 1 , {p.S.F + i , p.S.S + j}});
    				}
    			}
    		}
    	}
    }
    int32_t main(){
    	fast;
    	int t;
    	cin >> t;
    	while(t--)
    		solve();
    } 
