// https://community.topcoder.com/stat?c=problem_statement&pm=11359
// SRM 502 : Div 1 - level 1
// SRM 502 : Div 2 - level 2
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define all(c) (c).begin(),(c).end()
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(nullptr);

class TheLotteryBothDivs{
	public:
		double find(vector<string> v)
		{
			for(auto &x : v)
				reverse(all(x));

			int n = v.size();
			vector<int> a(n,1);
			
			for(int i=0 ; i<n ; i++)
			{
				for(int j=0 ; j<n ; j++)
				{
					if(i == j || v[i].size() < v[j].size() || a[j] == 0)  continue;
					if(v[i].substr(0,v[j].size()) == v[j])
						a[i] = 0;
				}
			}
			
			double ans = 0;
			f(i,0,n)
			{
				if(a[i])
					ans += (double)pow(10 , -(int)v[i].size());
			}
			return ans;
		}
};
