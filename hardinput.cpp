#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lo long long
  
int main() {
    int cnt = 0;
    string s, word;
    vector<vector<string> > v;
    while(getline(cin, s)){
        if(s == "q") break;
        stringstream in(s);
        vector<string> line;
        while(in >> word){
            line.push_back(word);
        }
        v.push_back(line);
    } 
    for(int i = 0; i < v.size(); i++){
        cout << "line " << i + 1 << ") {";
        for(int j = 0; j < v[i].size(); j++){
            if(j < v[i].size() - 1)
                cout << v[i][j] << ", ";
            else 
                cout << v[i][j];
        }
        cout << "}" << endl;
    }
    return 0;
}
