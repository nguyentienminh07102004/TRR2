#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int n; 
const int maxn=1001;
int a[maxn][maxn]; // ma tran ke
vector<pair<int, int>> edge; // danh sach canh
vector<int> adj[maxn];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
	cout<< endl;
   	cout<< "Chuyen doi tu Ma tran ke sang danh sach canh va danh sach ke" << endl; 
// Luu vao danh sach canh
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(a[i][j] == 1 && i < j){
        edge.push_back({i, j});
      }  else if(i>=j) continue;
    }
}
// In Edge-List:
	cout << endl;
	cout << "Edge List: " << endl;
  	for(auto item: edge) {
    cout << "("<<item.first  << "," << item.second <<")"<< endl;
  }
  
// Luu vao danh sach ke
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      	if(a[i][j] == 1 && i < j){
        	adj[i].push_back(j);
        	adj[j].push_back(i);
    	}else if(i>=j) continue;
    }
}
  
  	cout << endl << "Danh sach Ke" << endl;
// In danh sach ke
  	for(int i = 1; i <= n; i++) {
    	cout <<"Ke(" << i << ") : ";
    	for(int x: adj[i]) {
      		cout << x << " ";
    	}
    cout << endl;
  }
}
