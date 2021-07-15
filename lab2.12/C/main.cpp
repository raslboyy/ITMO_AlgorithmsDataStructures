#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

void print(vector<vector<bool>> &p, int i, int j, string &a, string &b) {
    if (i < 0 || j < 0) {
        return;
    }
    if (a[i] == b[j]) {
        print(p, i - 1, j - 1, a, b);
        cout << a[i];
    }
    else {
        if (p[i][j])
            print(p, i, j - 1, a, b);
        else
            print(p, i - 1, j, a, b);
    }

}

int main() {

  string a, b;
  cin >> a >> b;
  a = "#" + a;
  b = "%" + b;
  int n = a.size();
  int m = b.size();
  vector<int> dp(m);

  vector<vector<bool>> p(n, vector<bool>(m));
  for (int i = 1; i < n; i++) {
    vector<int> t;
    t = dp;
    for (int j = 1; j < m; j++) {
      if (a[i] == b[j])
        dp[j] = t[j - 1] + 1;
      else {
          if (dp[j - 1] > t[j]) {
              p[i][j] = true;
              dp[j] = dp[j - 1];
          }
          else {
              p[i][j] = false;
              dp[j] = t[j];
          }
      }
    }
  }

//  cout << dp[m - 1] << endl;
  print(p, n - 1, m - 1, a, b);



  return 0;
}
