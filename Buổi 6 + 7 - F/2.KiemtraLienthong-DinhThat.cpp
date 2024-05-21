
#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int> adj[1010];
bool visited[1010] = {0};
map<int,int> mp;

int u,v;


int dfs(int k) {
	visited[k] = true;
	if(k == v)return 1;
	int s = 0;
	for(int i : adj[k]) {
		if(!visited[i]) {
			s += dfs(i);
		} else s += mp[i];
	}
	mp[k] = s;
	return s;
}

bool con_check(int k) {
	visited[k] = true;
	if(k == v)return true;
	bool is_found = false;
	for(int i : adj[k]) {
		if(!visited[i]) {
			is_found |= con_check(i);
		}
	}
	return is_found;
}

int is_connected(int removed_node) {
	memset(visited,0,m+1);
	visited[removed_node] = true;
	return con_check(u);
}


int main() {
	int test;
	cin>>test;
	while(test--) {
		for(int i=1; i<=n; i++) {
			adj[i].clear();
			visited[i]=0;
		}
		cin>>n>>m>>u>>v;
		for(int i=1; i<=m; i++) {
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		mp[v] = 1;
		int ok = 0;
		int max = dfs(u);
		for(int i=1; i<=m; i++) {
			if(mp[i] && i != u && i != v) {
				if(!is_connected(i)) {
					cout << i << " "; // Dinh That
					ok = 1;
				}
			}
		}
		if(ok == 0) cout << "Khong co dinh that";
		cout << endl;
	}
}