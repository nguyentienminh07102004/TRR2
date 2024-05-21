#include<bits/stdc++.h>
using namespace std;

int n,m,v;
const  int maxn=1001;
set<int> adj[maxn];
int degree [maxn];

void nhap() {
	cin>>n>>m>>v;
	for(int i=0; i<m; i++) {
		int x,y;
		cin>>x>>y;
		adj[x].insert(y);
		adj[y].insert(x);
		degree[x]++;
		degree[y]++;
	}
}
void euler(int v) {
	stack<int> st;
	vector<int> ec;
	st.push(v);
	while(!st.empty()) {
	int x=st.top();
		if(adj[x].size()!=0) {
			int y = *adj[x].begin();
			st.push(y);
			//xoa (x, y);
			adj[x].erase(y);
			adj[y].erase(x);
		} else {
			st.pop();
			ec.push_back(x);
		}
	}
	reverse(begin(ec), end(ec));
	for(int x : ec) cout<< x << ' ';
}
int main() {
	nhap();
	euler(v);
}