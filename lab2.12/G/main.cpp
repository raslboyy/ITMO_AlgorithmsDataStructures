#include <iostream>
#include <vector>

using namespace std;

int main() {

  freopen("knapsack.in", "r", stdin);
  freopen("knapsack.out", "w", stdout);

  int s, n;
  cin >> s >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<bool> dp(s + 1);
  dp[0] = true;
  for (int i = 0; i < n; i++)
    for (int j = s - a[i]; j >= 0; j--)
      if (dp[j])
        dp[j + a[i]] = true;

  for (int i = s; i >= 0; i--)
    if (dp[i]) {
      cout << i << '\n';
      break;
    }

  return 0;
}
