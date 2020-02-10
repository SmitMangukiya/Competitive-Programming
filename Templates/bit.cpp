struct BIT
{
	int N;
	vector<int> bit;

	void inti(int n)
	{
		N = n;
		bit.assign(n+1 , 0);
	}

	void update(int pos , int val)
	{
		while(pos <= N)
		{
			bit[pos] += val;
			pos += pos & -pos;
		}
	}

	int pref(int pos)
	{
		int ans = 0;
		while(pos > 0)
		{
			ans += bit[pos];
			pos -= pos & -pos;
		}
		return ans;
	}

	int query(int l , int r)
	{
		return pref(r) - pref(l-1);
	}
};
