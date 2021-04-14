#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {

  freopen("pathsg.in", "r", stdin);
  freopen("pathsg.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n, INF));
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cin >> g[a][b];
  }
  for (int i = 0; i < n; i++)
    g[i][i] = 0;

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << g[i][j] << ' ';
    cout << '\n';
  }

  return 0;
}
