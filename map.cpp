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

int main(){
    string f, i, o, num;
    map< string, vector<string> > m;
    for(int j = 0; j < 5; j++){
        cin >> f >> i >> o >> num;
        m[f + " " + i + " " + o].push_back(num);
    }
    for (auto i : m) {
        cout << i.first << " : ";
        for(auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }
}
