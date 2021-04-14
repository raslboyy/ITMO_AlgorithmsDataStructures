#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF_I = 1e9;
const long long INF_LL = 1e18;

struct edge {
  int a;
  int b;
  int cost;
};

vector<int> p, sz;
long long res = 0;

int find_set(int v) {
  return (v == p[v] ? v : p[v] = find_set(p[v]));
}

void union_set(int a, int b, int w) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    res += w;
  }
}

int main() {

  freopen("spantree3.in", "r", stdin);
  freopen("spantree3.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  p.assign(n, 0);
  sz.assign(n, 1);
  sz.assign(n, 0);
  for (int i = 0; i < n; i++)
    p[i] = i;
  vector<edge> vec(m);
  for (int i = 0; i < m; i++) {
    cin >> vec[i].a >> vec[i].b >> vec[i].cost;
    vec[i].a--, vec[i].b--;
  }

  sort(vec.begin(), vec.end(), [](edge a, edge b) {
    return a.cost < b.cost;
  });

  for (edge e : vec)
    union_set(e.a, e.b, e.cost);
  cout << res << "\n";

  return 0;
}