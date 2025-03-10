#include <bits/stdc++.h>
using namespace std;

int n, s, t;
int mt[100][100];
stack<int> st, CE;

void init() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mt[i][j];
        }
    }
}

bool isEvenDegree() {
    int degree[100] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mt[i][j] == 1) {
                degree[i]++;
                degree[j]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (degree[i] & 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    if (!isEvenDegree()) {
        cout << "No Euler" << endl;
        return;
    }
    st.push(s);
    while (!st.empty()) {
        bool vs = false;
        s = st.top();
        for (int i = 1; i <= n; ++i) {
            if (mt[s][i] == 1) {
                // xóa cạnh s i trong đồ thị vô hướng
                mt[s][i] = mt[i][s] = 0;
                st.push(i);
                vs = true;
                break;
            }
        }
        if (!vs) {
            st.pop();
            CE.push(s);
        }
    }
}

void output() {
	while (!CE.empty()) {
        cout << CE.top() << " ";
        CE.pop();
    }
}

int main() {
    init();
    solve();
    output();
}