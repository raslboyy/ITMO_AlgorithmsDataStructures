#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pathbgep.in ", "r", stdin);
  freopen("pathbgep.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }


  set<pair<int, int>> s;
  vector<int> d(n, INT_MAX);
  d[0] = 0;
  s.emplace(0, 0);
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (auto &j : g[v])
      if (d[j.first] > d[v] + j.second) {
        if (s.find(make_pair(d[j.first], j.first)) != s.end())
          s.erase(make_pair(d[j.first], j.first));
        d[j.first] = d[v] + j.second;
        s.emplace(make_pair(d[j.first], j.first));
      }
  }

  for (int i = 0; i < n; i++)
    cout << d[i] << ' ';
  cout << '\n';

  return 0;
}
