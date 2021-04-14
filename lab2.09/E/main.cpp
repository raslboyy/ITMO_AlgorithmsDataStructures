#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>

using namespace std;

void top_sort(int v, vector<unordered_set<int>> &g, vector<bool> &used, vector<int> &o) {
  used[v] = true;
  for (int i : g[v])
    if (!used[i])
      top_sort(i, g, used, o);
  o.emplace_back(v);
}

int main() {
//  freopen("hamiltonian.in", "r", stdin);
//  freopen("hamiltonian.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<unordered_set<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace(b);
  }

  vector<int> o;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++)
    if (!used[i])
      top_sort(i, g, used, o);
  reverse(o.begin(), o.end());

  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ';
  cout << '\n';
  for (int i = 0; i < n - 1; i++)
    if (g[o[i]].find(o[i + 1]) == g[o[i]].end()) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";

  return 0;
}
