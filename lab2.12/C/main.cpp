#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {



  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  vector<int> dp(m);

  for (int i = 0; i < n; i++) {
    vector<int> t;
    if (i == 0)
      t = vector<int>(m, 0);
    else
      t = dp;
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j])
        dp[j] = max(dp[j], (j > 0 ? t[j - 1] : 0) + 1);
      else if (j > 0)
        dp[j] = max(dp[j], t[j - 1]);
    }
  }

  int k = 1;
  for (int i = 0; i < m; i++)
    if (dp[i] == k) {
      cout << b[i];
      k++;
    }


  return 0;
}
