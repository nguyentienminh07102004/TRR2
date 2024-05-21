//2.EdgeList
#include<bits/stdc++.h>
using namespace std;

const int maxn=1001;
int n, m; //n: dinh, m: canh
int a[maxn][maxn];
vector<int> b[maxn];
	
int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1; // Do thi vo huong
	// DSK 
	b[x].push_back(y);
	b[y].push_back(x);
}
//  
	cout << "  Ma tran Ke" << endl;
  	for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

// 
	cout << endl;
	cout << "  Danh sach ke " << endl; 
	for(int i=1;i<=n;i++){
		cout << "Ke(" << i << ") : ";
		for(int x: b[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}