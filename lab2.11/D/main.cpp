#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

struct edge {
  int a;
  int b;
  ll c;
};

const ll INF = LLONG_MAX - 1e15 - 2;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("path.in ", "r", stdin);
  freopen("path.out", "w", stdout);

  int n, m, st;
  cin >> n >> m >> st;
  st--;
  vector<edge> e(m);
  vector<vector<int>> g(n, vector<int>());
  for (int i = 0; i < m; i++) {
    cin >> e[i].a >> e[i].b >> e[i].c;
    e[i].a--;
    e[i].b--;
    g[e[i].a].emplace_back(e[i].b);
  }

  vector<ll> d(n, INF);
  vector<bool> is(n, false);
  vector<int> p(n, -1);
  d[st] = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m; j++)
      if (d[e[j].a] < INF && d[e[j].b] > d[e[j].a] + e[j].c) {
        d[e[j].b] = max(-INF, d[e[j].a] + e[j].c);
        p[e[j].b] = e[j].a;
      }


  vector<bool> u(n, true);
  for (int j = 0; j < m; j++)
    if (d[e[j].a] < INF && d[e[j].b] > d[e[j].a] + e[j].c) {
      d[e[j].b] = max(-INF, d[e[j].a] + e[j].c);
      p[e[j].b] = e[j].a;
      int prev = p[e[j].b];
      for (int i = 0; i < n; i++)
        prev = p[prev];

      queue<int> q;
      u[prev] = false;
      q.push(prev);
      while (!q.empty()) {
        is[q.front()] = true;

        for (int to : g[q.front()]) {
          if (u[to]) {
            q.push(to);
            u[to] = false;
          }
        }
        q.pop();
      }
    }


  for (int i = 0; i < n; i++) {
    if (d[i] == INF)
      cout << '*' << '\n';
    else if (is[i])
      cout << '-' << '\n';
    else
      cout << d[i] <<'\n';
  }



  return 0;
}
