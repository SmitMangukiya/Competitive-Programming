// n - numer of vertex
// m - number of edge
// d - distance from source

void dijikstra()
{
	int n,m , source , destination;
	cin >> n >> m;

	vector<vector<pair<int,int>>> graph(n + 1);

	vector<int> d(n + 1 , inf);

	for(int i=1 ; i<=m ; i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		graph[x].pb({y,w});
		graph[y].pb({x,w});
	}

	cin >> source >> destination;

	set<pair<int,int>> s;

	s.insert({0 , source});
	d[source] = 0;

	while(!s.empty())
	{
		auto p = *s.begin();
		s.erase(p);

		int v = p.S ;
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

}
