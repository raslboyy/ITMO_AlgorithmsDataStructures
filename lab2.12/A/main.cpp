#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

//  freopen("pathmgep.in", "r", stdin);
//  freopen("pathmgep.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> dp(n, 1);

  int m = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++)
      if (a[j] < a[i])
        dp[i] = max(dp[i], dp[j] + 1);
    if (dp[i] > dp[m])
      m = i;
  }

  vector<int> b(dp[m]);
  for (int i = dp[m] - 1; i >= 0; i--) {
    b[i] = a[m];
    for (int j = m - 1; j >= 0; j--)
      if (dp[j] == dp[m] - 1) {
        m = j;
        break;
      }
  }
  cout << b.size() << '\n';
  for (int i : b)
    cout << i << ' ';
  cout << '\n';

  return 0;
}
