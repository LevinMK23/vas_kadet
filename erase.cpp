#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lo long long
  
int main() {
    int cnt = 0;
    string s = "abcdefabcdefabcdef", word, target = "cde";
    word = s;
    while(word.find(target) < word.size()){
        cnt++;
        cout << word.find(target) << " ";
        word.erase(word.find(target), target.size());
    }
    cout << word << endl << cnt;
    return 0;
}
