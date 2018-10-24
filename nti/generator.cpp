#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

long ans = 0;
vector<int> res(11, 0);

long gen(int n, int i, int j) {
  if (n == 0 && i == 11 && j <= 10) {
    for(int x = 0; x < i; x++) {
      if(res[x] == 10) cout << 0;
      else 
        cout << (res[x]);
    }
    cout << endl;
    int co = 1, mul = 1;
    for(int m = 10; m >= 0; m--){
      co = 1;
      for(int l = m - 1; l >= 0; l--){
        if(res[m] != res[l]) co++;
      }
      mul *= co;
    }
    ans += mul;
    return 1;
  }
  if (j > 10 || i > 11) return 0;
  res[i] = j;
  return gen(n - j, i + 1, j) + gen(n, i, j + 1);
}

int main(){
  gen(14, 0, 1);
  cout << ans;
  return 0;
}
