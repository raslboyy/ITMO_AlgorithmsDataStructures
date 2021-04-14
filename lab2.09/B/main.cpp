#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void dfs(int v, vector<list<int>> &g, vector<int> &color, vector<int> &p) {
  color[v] = 1;
  for (int i : g[v]) {
    if (color[i] == 1) {
      cout << "YES\n";
      int cur = v;
      vector<int> cycle;
      while (cur != i) {
        cycle.emplace_back(cur);
        cur = p[cur];
      }
      cycle.emplace_back(i);
      reverse(cycle.begin(), cycle.end());
      for (int j : cycle)
        cout << j + 1 << ' ';
      exit(0);
    }
    else if (color[i] == 0) {
      p[i] = v;
      dfs(i, g, color, p);
    }
  }
  color[v] = 2;
}

int main() {

  freopen("cycle.in", "r", stdin);
  freopen("cycle.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<list<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
  }

  vector<int> color(n, 0);
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++)
    if (color[i] == 0)
      dfs(i, g, color, p);


  cout << "NO\n";
  return 0;
}
