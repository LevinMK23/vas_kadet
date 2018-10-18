#include <bits/stdc++.h>
using namespace std;

double def = -2.71;

struct sqrEq{
    double x = def, x1 = def, x2 = def;
    bool noroots = false;
};

sqrEq calc(double a, double b, double c){
    sqrEq ans;
    if(b * b - 4 * a * c < 0){
        ans.noroots = true;
    }
    else if(b * b - 4 * a * c == 0){
        ans.x = -b / (2 * a);
    }
    else{
        ans.x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        ans.x2 = (-b  + sqrt(b * b - 4 * a * c)) / (2 * a);
    }
    return ans;
}

int main(){
    double l = 0, r = 1000000001, tmp = 0, n, e = 0.0000001;
    cin >> n;
    while(abs(r-l) > e){
        double mid = (l + r) / 2;
        if(mid * mid == n){
            cout << mid;
            return 0;
        }
        else if(mid * mid < n){
            l = mid;
        }
        else r = mid;
    }
    printf("%0.7f", l);
    return 0;
}
