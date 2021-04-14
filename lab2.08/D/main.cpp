#include <iostream>
#include <vector>

using namespace std;

vector<int> color;
vector<vector<int>> g;

void dfs(int v, int current_color) {
  if (color[v] != 0)
    return;
  color[v] = current_color;
  for (int to : g[v])
    dfs(to, current_color);
}

int main() {
  freopen("components.in", "r", stdin);
  freopen("components.out", "w", stdout);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  color.assign(n, 0);
  g.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  int count = 1;
  for (int i = 0; i < n; i++)
    if (color[i] == 0)
      dfs(i, count++);

  cout << count - 1 << '\n';
  for (int i = 0; i < n; i++)
    cout << color[i] << ' ';

  return 0;
}
