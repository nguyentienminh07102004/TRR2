#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int Root[105];
int Size[105];
int res, v, e;
vector<pair<pair<int, int>, int>> vp;

inline int findRoot(int x) {
	if(x == Root[x])
		return x;
	return Root[x] = findRoot(Root[x]);
}

inline void Union(int x, int y, pair<pair<int, int>, int> p) {
	int rootX = findRoot(x), rootY = findRoot(y);
	if(rootX != rootY) {
		res += p.se;
		if(Size[rootX] < Size[rootY])
			swap(rootX, rootY);
		Root[rootY] = rootX;
		Size[rootX] += Size[rootY];
	}
}

inline bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.se < b.se;
}

int main() {
	int t, x, y, z;
	cin >> t;
	while(t--) {
		cin >> v >> e;
		for(int i = 1; i <= v; ++i) {
			Root[i] = i;
			Size[i] = 1;
		}
		while(e--) {
			cin >> x >> y >> z;
			vp.push_back({{x, y}, z});
		}
		sort(vp.begin(), vp.end(), cmp);
		res = 0;
		for(pair<pair<int, int>, int> &i : vp)
			Union(i.fi.fi, i.fi.se, i);
		cout << res << endl;
		vp.clear();
	}
	return 0;
}