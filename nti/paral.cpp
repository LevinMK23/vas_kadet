#include <bits/stdc++.h>
using namespace std;


struct point{
    double x, y;
};

struct ans{
    double x, y, d;
};

bool cmp(ans a, ans b){
    if(a.d < b.d) return true;
    else if(a.d == b.d){
        if(a.x + a.y < b.x + b.y) return true;
        else if(a.x + a.y == b.x + b.y){
            if(a.x < b.x) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

int main(){
    point p[5];
    vector<ans> a;
    double dis, x, y, dx, dy;
    int px = 1, py = 2, pz = 3;
    for(int i = 1; i < 4; i++){
        cin >> p[i].x >> p[i].y;
    }
    int c = 0;
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(i != j){
                px = i;
                py = j;
                pz = 6 - i - j;
                dx = p[px].x - p[pz].x;
                dy = p[px].y - p[pz].y;
                x = p[py].x + dx;
                y = p[py].y + dy;
                dis = max(
                sqrt((p[pz].y - y)*(p[pz].y - y) + (p[pz].x - x) * (p[pz].x - x)), 
                sqrt(pow(p[px].x-p[py].x, 2) + pow(p[px].y-p[py].y, 2)));
                ans o; 
                o.x = x; 
                o.y = y; 
                o.d = dis;
                a.push_back(o);
            }
        }
    }
    sort(a.begin(), a.end(), cmp);
    printf("%lld %lld", (long long)a[a.size()-1].x, (long long)a[a.size()-1].y);
}
