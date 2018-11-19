#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
#define lo long long

int g[110][110];
map<int, int> h;

void dfs(int i, int j, int n, int m){
    if(!(i >= 0 && i < n && j >= 0 && j < m)){
        return;
    }
    if(g[i][j] == 1) return;
    if(h.find(n * i + j) == h.end()){
        h[n * i + j] = 1;
        dfs(i-1, j, n, m);
        dfs(i, j-1, n, m);
        dfs(i, j+1, n, m);
        dfs(i+1, j, n, m);
    }
}
 
 
int main() {
    int n, m;
    cin >> n >> m;
    char c;
    int cnt  = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> c;
            g[i][j] = (c == '.' ? 1 : 0);    
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(h.find(n * i + j) == h.end() && g[i][j] != 1){
                dfs(i, j, n, m);
                cnt++;
            }
        } 
    cout << cnt;     
    return 0; 
}
