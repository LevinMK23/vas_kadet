#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#define long long long
using namespace std;

struct node{
    int n;
    set<int> s;
};

bool cmp(node n1, node n2){
    //return true;
    return n1.s.size() > n2.s.size();
}

int main(){
    int n, t, from, to;
    cin >> n >> t;
    vector<node> v(n+1);
    for (int i = 1; i <= n; i++) {
        v[i].n = i;
    }
    for (int i = 0; i < t; i++) {
        cin >> from >> to;
        v[from].s.insert(to);
        v[to].s.insert(from);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) {
        cout << i.n << " : ";
        for (auto j : i.s) {
            cout << j << " ";
        }
        cout << endl;
    }
}
