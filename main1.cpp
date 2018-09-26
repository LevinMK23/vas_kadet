#include <iostream>
#include <vector>
#include <map>
#include <set>
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
    string fio;
};

bool cmp(point x, point y){
    return x.x * x.x + x.y * x.y < y.x * y.x + y.y * y.y;
}

int main(){
    int n;
    cin >> n;
    point a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y << endl;
    }
    return 0;
}
