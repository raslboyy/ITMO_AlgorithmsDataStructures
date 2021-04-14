#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void top_sort(int v, vector<list<int>> &g, vector<bool> &used, vector<int> &o) {
  used[v] = true;
  for (int i : g[v])
    if (!used[i])
      top_sort(i, g, used, o);
  o.emplace_back(v);
}

void dfs(int v, vector<list<int>> &g, vector<int> &color, int count) {
  color[v] = count;
  for (int to : g[v])
    if (color[to] == 0)
      dfs(to, g, color, count);
}

int main() {
  freopen("cond.in", "r", stdin);
  freopen("cond.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<list<int>> g(n);
  vector<list<int>> r_g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    r_g[b].emplace_back(a);
  }

  vector<int> o;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++)
    if (!used[i])
      top_sort(i, g, used, o);
  reverse(o.begin(), o.end());

  vector<int> color(n, 0);
  int count = 1;
  for (int i = 0; i < n; i++)
    if (color[o[i]] == 0)
      dfs(o[i], r_g, color, count++);

  cout << count - 1 << '\n';
  for (int i = 0; i < n; i++)
    cout << color[i] << ' ';

  return 0;
}
