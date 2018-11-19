#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
#define lo long long

int cnt = 0;
vector<int> friends;
vector<char> used(101, false);
vector<int> color(101, 0);
bool flag = true;

void show(vector<int> v){
    for(auto i : v) cout << i << " ";
    cout << endl;
}

void show(set<int> v){
    for(auto i : v) cout << i << " ";
    cout << endl;
}

void dfs(vector< vector<int> > g, int v){
    for(int i = 0; i < g[v].size(); ++i){
        if(color[g[v][i]] == 0){
            color[g[v][i]] = 3 - color[v];
            dfs(g, g[v][i]);
        }
        else{
            if(color[g[v][i]] == color[v]){
                flag = false;
            }
        }
    }
}
 
void showList(vector< vector<int> > g){
    for(int i = 1; i < g.size(); ++i){
        cout << i << " : ";
        for (int j = 0; j < g[i].size(); ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    int n, m, f, t, e = 0;
    cin >> n >> m;
    color[1] = 1;
    vector< vector<int> > g(n+1);
    while(m--){
        cin >> f >> t;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    dfs(g, 1);
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            color[i] = 1;
            dfs(g, i);
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0; 
}
