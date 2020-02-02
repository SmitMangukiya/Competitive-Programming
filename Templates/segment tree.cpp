
const int N = 1e5 + 5;
int n,a[N] , t[4*N];
void build(int v , int tl , int tr)
{
	if(tl == tr)
		t[v] = a[tl];
	else
	{
		int tm = (tl + tr)/2;
		build(2*v , tl , tm);
		build(2*v + 1 , tm + 1 , tr);
		t[v] = min(t[2*v] , t[2*v + 1]);
	}
}

void update(int v  , int tl , int tr , int pos , int val)
{
	if(tl == tr)  t[v] = val;
	else
	{
		int tm = (tl + tr)/2;
		if(pos >= tl && pos <= tm)
			update(2*v , tl , tm , pos , val);
		else
			update(2*v + 1, tm + 1 , tr , pos , val);
		t[v] = min(t[2*v] , t[2*v+1]);
	}
}

int query(int v , int tl , int tr , int l ,int r)
{
	if(tl > r || tr < l)   return LLONG_MAX;
	if(tl >= l && tr <= r)  return t[v];
	else
	{
		int tm = (tl + tr)/2;
		int p1 = query(2*v , tl , tm , l ,r);
		int p2 = query(2*v + 1 , tm + 1, tr , l , r);
		return min(p1 , p2);
	}
}


