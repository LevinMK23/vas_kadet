#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, t, f, s = 0;
    cin >> n;
    vector< vector<int> > g(n);
    string ss[n], s1, s2;
    for(int i = 0; i < n; i++) cin >> ss[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> s1 >> s2;
        int f, t;
        for(int j = 0; j < n; j++){
            if(ss[j] == s1) f = j;
            if(ss[j] == s2) t = j;
        }
        g[f].push_back(t);
        g[t].push_back(f);
    }
    queue<int> q;
    q.push (s);
    vector<bool> used (n,  false);
    vector<int> d (n), p (n);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
	    int v = q.front();
	    q.pop();
        for (size_t i=0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    for(int i = 0; i < n; i++) if(d[i] > 6){
        cout << "No"; return 0;
    }
    cout << "Yes";
}
