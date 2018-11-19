#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
#define lo long long



vector<char> used(100, false);

void dfs(vector< vector<int> > g, int v){
    
}

void showMatrix(vector< vector<int> > g){
    for(int i = 1; i < g.size(); ++i){
        for (int j = 1; j < g.size(); ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
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

bool is_lower(char c){
    return c >= 'a' && c <= 'z';
}

string to_upper(string s){
    for(int i = 0; i < s.size(); i++){
        if(is_lower(s[i])){
            s[i] -= 'a'-'A';
        }
    }
    return s;
}

int main() {
    /*string s, tmp;
    getline(cin, s);
    stringstream in(s);
    int cnt = 0;
    while(in >> tmp){
        cnt++;
    }
    
    cout << cnt << endl;*/
    int n, m, from, to;
    cin >> n >> m;
    vector< vector<int> > g(n+1);
    while(m--){
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    showList(g);
    /*vector< vector<int> > g(n+1, vector<int>(n+1));
    while (m--) {
        cin >> from >> to;
        g[from][to] = 1;
        g[to][from] = 1;
    }
    showMatrix(g);*/
}
