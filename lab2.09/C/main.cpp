#include <iostream>
#include <vector>
#include <list>

using namespace std;

void dfs(int v, vector<list<int>> &g, vector<int>& color) {
  for (int to : g[v]) {
    if (color[to] == -1) {
      color[to] = (color[v] + 1) % 2;
      dfs(to, g, color);
    }
    else if (color[to] != (color[v] + 1) % 2) {
      cout << "NO\n";
      exit(0);
    }
  }

}

int main() {

  freopen("bipartite.in", "r", stdin);
  freopen("bipartite.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<list<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  vector<int> color(n, -1);
  for (int i = 0; i < n; i++)
    if (color[i] == -1) {
      color[i] = 0;
      dfs(i, g, color);
    }
  cout << "YES\n";

  return 0;
}
