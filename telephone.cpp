#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long num = 89110000000;

int main() {
    int n;
    cin >> n;
    map<string, vector<long long> > m;
    string s;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        m[s].push_back(num++);
    }
    for(auto i : m){
        cout << i.first << " : ";
        for(auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
