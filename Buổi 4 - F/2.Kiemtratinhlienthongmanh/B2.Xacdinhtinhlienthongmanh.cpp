#include <bits/stdc++.h>
using namespace std;

int n, u, v, cou;
vector<vector<int>> G;
vector<int> vs;

void dfs(int s) {
    vs.clear();
    vs.resize(n + 1, 0);

    stack<int> st;
    st.push(s);
    vs[s] = 1;

    while (!st.empty()) {
        u = st.top();
        st.pop();

        for (int v : G[u]) {
            if (!vs[v]) {
                vs[v] = 1;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
}

int main() {
    cin >> n;
    G.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> u;
            if (u == 1) {
                G[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        for (int j = 1; j <= n; ++j) {
            if (!vs[j]) {
                cout << "No";
                return 0;
            }
        }
        
    }
    cout << "Yes";
    return 0;
}
// do thi co huong lien thong manh khi tu 1 diem bat ky trong do thi deu co duong di den cac diem con lai trong do thi