#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  for (int i = 0; i < n; i++)
    cout << g[i].size() << ' ';
  cout << '\n';

  return 0;
}
