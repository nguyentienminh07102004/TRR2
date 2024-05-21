#include<bits/stdc++.h>
using namespace std;
int n,s,t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u) {
	visited[u]=true;
	for(int v:adj[u]) {
		if(!visited[v]) {
			parent[v]=u;
			dfs(v);
		}
	}
}

void Path(int s, int t) {
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	dfs(s);
	if(!visited[t]) cout<<"no path";
	else {
		vector<int> path;
		while(t!=s) {
			path.push_back(t);
			t=parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int x:path) {
			cout<<x<<" ";
		}

	}
}
void input() {
	cin>>n;
	cin.ignore();
	for(int i=1; i<=n; i++) {
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		while(ss>>tmp) {
			int cnv;
			cnv=stoi(tmp);
			adj[i].push_back(cnv);
		}
	}
	cin>>s>>t;
}
int main() {
	ios_base::sync_with_stdio(0)
	cin.tie(0); cout.tie(0);
	for(int i=1; i<=n; i++) adj[i].clear();
	input();
	Path(s,t);
	return 0;
}