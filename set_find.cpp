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
    int m, n, t;
    cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> t;
        s.insert(t);
    }
    for(auto i : s) cout << i << " ";
    cout << endl;
    for(int i = 0; i < m; i++){
        cin >> t;
        if(s.find(t) != s.end()){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
