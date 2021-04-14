#include <iostream>
#include <vector>

using namespace std;

bool check(int a, int b, int n, int m) {
  return  a >= 0 && b >= 0 && a < n && b < m;
}

int main() {

  freopen("knight2.in", "r", stdin);
  freopen("knight2.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = 1;
  for (int i = 0; i < n + m - 1; i++)
    for (int j = 0; j <= i; j++) {
      int a = j;
      int b = i - j;
      if (!check(a, b, n, m))
        continue;
      if (check(a - 1, b + 2, n, m))
        dp[a - 1][b + 2] += dp[a][b];
      if (check(a + 1, b + 2, n, m))
        dp[a + 1][b + 2] += dp[a][b];
      if (check(a + 2, b + 1, n, m))
        dp[a + 2][b + 1] += dp[a][b];
      if (check(a + 2, b - 1, n, m))
        dp[a + 2][b - 1] += dp[a][b];
    }
  cout << dp[n - 1][m - 1] << '\n';

  return 0;
}
