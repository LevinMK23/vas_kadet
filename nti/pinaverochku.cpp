#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    double r = 6371302, x1, y1, x2, y2, g = 3.1415926535897 / 180;
    cin >> x1 >> y1 >> x2 >> y2;
    x1*=g; y1 *= g; x2 *= g; y2 *= g;
    double sx1 = sin(x1), sx2 = sin(x2), csx1 = cos(x1), csx2 = cos(x2),
    csDel = cos(y2-y1);
    cout << int(r * acos(sx1 * sx2 + csx1 * csx2 * csDel) / 1000 + 0.5);
}
