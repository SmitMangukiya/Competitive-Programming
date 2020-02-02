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
    const int N = 10005;
    vector<vector<pair<int,int>>> graph(N + 1);
     
    int dijikstra(int source , int destination)
    {
     
    	vector<int> d(N , inf64);
     
    	set<pair<int,int>> s;
     
    	s.insert({0 , source});
    	d[source] = 0;
     
    	while(!s.empty())
    	{
    		auto u = *s.begin();
    		s.erase(u);
     
    		int v = u.S ;
    		for(auto edge : graph[v])
    		{
    			int to = edge.F;
    			int len = edge.S;
     
    			if(d[to] > d[v] + len)
    			{
    				s.erase({d[to] , to});
    				d[to] = d[v] + len;
    				s.insert({d[to] , to});
    			}
    		}
    	}
    	return d[destination];
    }
    int32_t main(){
    	fast;
    	int t;
    	cin >> t;
    	while(t--)
    	{
    		map<string , int> city;
    		
    		int n,m;
    		cin >> n;
    		for(int i=1 ; i<=n ;i++)
    		{
    			string s;
    			cin >> s;
    			city[s] = i;
    			
    			cin >> m;
    			for(int j=1 ; j<=m ; j++)
    			{
    				int v,w;
    				cin >> v >> w;
    				graph[i].pb({v,w});
    			}
    		}
    		
    		int q;
    		cin >> q;
    		while(q--)
    		{
    			string u,v;
    			cin >> u >> v;
    			cout << dijikstra(city[u] , city[v]) << "\n";
    		}
    		for(int i=0 ; i<N ; i++)
    			graph[i].clear();
    			
    	}
    } 
