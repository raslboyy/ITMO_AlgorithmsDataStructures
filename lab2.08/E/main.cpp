#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
  freopen("pathbge1.in", "r", stdin);
  freopen("pathbge1.out", "w", stdout);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  queue<int> q;
  vector<int> d(n, -1);
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to : g[v])
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        q.push(to);
      }
  }

  for (int i = 0; i < n; i++)
    cout << d[i] << ' ';
 
  return 0;
}