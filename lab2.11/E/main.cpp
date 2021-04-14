#include <iostream>
#include <vector>

using namespace std;

struct edge{
  int a;
  int b;
  int c;
};

const int INF = 1e9;
vector<int> d;
vector<int> p;

void foo(vector<edge>& e, int n, int m, int st) {
  d[st] = st;
  int x = 0;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (int j = 0; j < m; j++)
      if (d[e[j].a] < INF && d[e[j].b] > d[e[j].a] + e[j].c) {
        d[e[j].b] = max(-INF, d[e[j].a] + e[j].c);
        p[e[j].b] = e[j].a;
        x = e[j].b;
      }
  }

  if (x != -1) {
    cout << "YES\n";
    int prev = p[x];
    for (int i = 0; i < n; i++)
      prev = p[prev];

    vector<int> res;
    for (int i = p[prev]; i != prev; i = p[i])
      res.emplace_back(i);
    cout << res.size() + 2 << '\n';
    cout << prev + 1 << ' ';
    for (int i = (int)res.size() - 1; i >= 0; i--)
      cout << res[i] + 1 << ' ';
    cout << prev + 1 << ' ';
    exit(0);
  }
}

int main() {

  freopen("negcycle.in ", "r", stdin);
  freopen("negcycle.out", "w", stdout);

  int n;
  cin >> n;
  vector<edge> e;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a != INF)
        e.emplace_back(edge{i, j, a});
    }

  d.assign(n, INF);
  p.assign(n, -1);
  int m = e.size();
  for (int i = 0; i < n; i++)
    if (d[i] == INF)
      foo(e, n, m, i);

  cout << "NO\n";


  return 0;
}
