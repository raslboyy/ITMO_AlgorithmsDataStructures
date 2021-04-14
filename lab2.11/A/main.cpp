#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pathmgep.in", "r", stdin);
  freopen("pathmgep.out", "w", stdout);

  int n, s, f;
  cin >> n >> s >> f;
  s--, f--;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> g[i][j];

  vector<ll> d(n, LLONG_MAX);
  vector<bool> u(n, true);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int j = 0; j < n; j++)
      if (u[j] && (v == -1 || d[j] < d[v]))
        v = j;
    if (d[v] == LLONG_MAX || v == f)
      break;
    u[v] = false;
    for (int j = 0; j < n; j++)
      if (g[v][j] != -1)
        d[j] = min(d[j], d[v] + g[v][j]);
  }

  cout << (d[f] == LLONG_MAX ? -1 : d[f]) << '\n';

  return 0;
}
