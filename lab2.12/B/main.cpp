#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> dp(n + 1, INT_MAX);
  vector<int> dpIndex(n + 1, -1);
  vector<int> p(n, -1);
  dp[0] = INT_MIN;
  for (int i = 0; i < n; i++) {
    int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if (a[i] > dp[j - 1] && dp[j] > a[i]) {
      dp[j] = a[i];
      dpIndex[j] = i;
      p[i] = dpIndex[j - 1];
    }
  }

  stack<int> out;
  for (int i = n; i >= 0; i--)
    if (dp[i] != INT_MAX) {
      cout << i << '\n';
      for (int v = dpIndex[i]; v != -1; v = p[v])
        out.push(a[v]);
      break;
    }

  for (; !out.empty(); out.pop())
    cout << out.top() << ' ';


  return 0;
}
