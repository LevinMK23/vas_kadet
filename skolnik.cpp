#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;


vector<int> sieve(int n){
    vector<int> v;
    int p[n+1];
    for (int i = 0; i <= n; i++) {
        p[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] == 1) {
            if((long long) i * i <= n)
            for (int j = i * i; j <= n; j += i) {
                p[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if(p[i]) v.push_back(i);
    }
    return v;
}

struct point{
    int x, y;
};

struct shkolnik{
    string fio = "";
    double ans = 0;
    vector<int> marks;
    void compute(){
        int c = 0, sum = 0;
        for(auto i : marks){
            sum += i;
            c++;
        }
        ans = (double)sum / c;
    }
};

bool shkolnik_cmp(shkolnik normal, shkolnik smoker){
    return normal.ans > smoker.ans;
}

bool cmp(point x, point y){
    return x.x * x.x + x.y * x.y < y.x * y.x + y.y * y.y;
}

int main(){
    int n, t;
    string s, s1;
    cin >> n;
    getline(cin, s);
    shkolnik simple[n];
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream in(s);
        string tmp;
        for(int j = 0; j < 3; j++){
            in >> tmp;
            simple[i].fio += tmp + " ";
        }
        while (in >> t) {
            simple[i].marks.push_back(t);
        }
        simple[i].compute();
    }
    sort(simple, simple + n, shkolnik_cmp);
    for(auto s : simple){
        cout << s.fio << " " << s.ans << endl;
    }
    return 0;
}
