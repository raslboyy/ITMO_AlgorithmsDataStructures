#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;

int main() {

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    dp[i][i] = 1;

  for (int len = 2; len <= n; len++)
    for (int begin = 0; begin <= n - len; begin++)

  return 0;
}
