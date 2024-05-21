#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10000;

vector<int> adj[MAXN]; 
bool visited[MAXN]; 
int disc[MAXN], low[MAXN]; 
int timeCounter; 
bool hasBridge; 

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) { 
                cout << "Bridge found: " << u << " - " << v << endl;
                hasBridge = true;
            }
        } else if(v != parent) {
            
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges(int n) {
    timeCounter = 0;
    hasBridge = false;
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        disc[i] = -1;
        low[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    if (!hasBridge) {
        cout << "No Bridge" << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m; 
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    findBridges(n);
    return 0;
}
