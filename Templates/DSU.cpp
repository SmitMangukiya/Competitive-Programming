int id[N];
int sz[N];

void pre(){
	
	for(int i= 0 ; i<N ; i++) id[i] = i , sz[i] = 1;
}

int root(int i){
	
	while(i != id[i])	id[i] = id[id[i]] , i = id[i];
	return i;
}

void uni(int a, int b){
	int ra = root(a);
	int rb = root(b);
	if(ra == rb)	return;
	if(sz[ra] < sz[rb]) swap(ra,rb);
	id[rb] = ra , sz[ra] += sz[rb];
}


