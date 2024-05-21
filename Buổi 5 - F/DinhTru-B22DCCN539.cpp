//Stack
#include<iostream>
#include<vector>
#include<stack>
#define NIL -1
using namespace std;

int count=0;
class Graph {
    int V;
    vector<int> *adj;
    void APUtil(vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, stack<int> &st);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void AP();
    void inputGraph();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::AP() {
    vector<bool> visited(V, false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> parent(V, NIL);
    vector<bool> ap(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            APUtil(visited, disc, low, parent, ap, st); 
    	else{
			cout << "Khong co dinh tru" << endl;
			return;	
		}

    for (int i = 0; i < V; i++)
        if (ap[i]){
			while(count==0) {
			cout << "Cac dinh tru la: ";
			count++;
			}
			cout << i << " ";
    	}
	cout << endl;
}

void Graph::APUtil(vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, stack<int> &st) {
    static int time = 0;
    for(int u = 0; u < V; u++) {
        if (!visited[u]) {
            st.push(u);
            visited[u] = true;
            disc[u] = low[u] = ++time;

            while (!st.empty()) {
                int v = st.top();
                bool isLeaf = true;

                for (int n : adj[v]) {
                    if (!visited[n]) {
                        st.push(n);
                        visited[n] = true;
                        parent[n] = v;
                        disc[n] = low[n] = ++time;
                        isLeaf = false;
                        break; 
                    } else if (n != parent[v]) {
                        low[v] = min(low[v], disc[n]);
                    }
                }

                if (isLeaf) {
                    st.pop();
                    if (parent[v] != NIL) {
                        low[parent[v]] = min(low[parent[v]], low[v]);
                        if (low[v] >= disc[parent[v]]) {
                            ap[parent[v]] = true;
                        }
                    }
                }
            }
        }
    }
}

void Graph::inputGraph() {
    int numAdjVertices, vertex;
    for (int i = 0; i < V; i++) {
        cout << "Nhap so dinh ke voi dinh " << i << ": ";
        cin >> numAdjVertices;
        cout << "Ke(" << i  << ")"<< " = ";
        for (int j = 0; j < numAdjVertices; j++) {
            cin >> vertex;
            addEdge(i, vertex);
        }
    }
}

int main() {
    int V;
    cout << "So dinh: ";
    cin >> V;

    Graph g(V);
    g.inputGraph();
    g.AP();

    return 0;
}