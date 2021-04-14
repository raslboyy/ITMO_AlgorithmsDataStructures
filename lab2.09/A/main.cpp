#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void dfs(int v, int p, vector<list<int>> &g, vector<int> &color, vector<int> &top_sort) {
  color[v] = 1;
  for (int i : g[v]) {
    if (i != p && color[i] == 1) {
      cout << "-1\n";
      exit(0);
    }
    else if (i != p && color[i] == 0)
      dfs(i, v, g, color, top_sort);
  }
  color[v] = 2;
  top_sort.emplace_back(v);
}

int main() {

  freopen("topsort.in", "r", stdin);
  freopen("topsort.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<list<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
  }

  vector<int> top_sort;
  vector<int> color(n, 0);
  for (int i = 0; i < n; i++)
    if (color[i] == 0)
      dfs(i, -1, g, color, top_sort);

  reverse(top_sort.begin(), top_sort.end());
  for (int i : top_sort)
    cout << i + 1 << ' ';

  return 0;
}
