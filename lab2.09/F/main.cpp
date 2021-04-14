#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> g;
vector<int> color;

void dfs(int v) {
  bool is_list = true;
  color[v] = 0;
  for (int to : g[v]) {
    if (color[to] == -1)
      dfs(to);
    color[v] += color[to];
    is_list = false;
  }
  if (is_list) {
    color[v] = 0;
    return;
  }
  if (color[v] != g[v].size())
    color[v] = 1;
  else
    color[v] = 0;
}

int main() {


  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  int s, n, m;
  cin >> n >> m >> s;
  s--;
  g.assign(n, list<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
  }

  color.assign(n, -1);
  dfs(s);
  if (color[s] == 0)
    cout << "Second player wins\n";
  else
    cout << "First player wins\n";

  return 0;
}
