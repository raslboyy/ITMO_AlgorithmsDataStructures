#include <iostream>
#include <vector>
#include <functional>

using namespace std;

const int INF = 1e9 + 1;

struct Edge {

  int from;
  int to;
  int weight;
};

void top_sort(int v, vector<vector<Edge>> &g, vector<bool> &used, vector<int> &o) {
  used[v] = true;
  for (auto &i : g[v])
    if (!used[i.to])
      top_sort(i.to, g, used, o);
  o.emplace_back(v);
}

void dfs(int v, vector<vector<Edge>> &g, vector<int> &color, int count) {
  color[v] = count;
  for (auto &i : g[v])
    if (color[i.to] == -1)
      dfs(i.to, g, color, count);
}

vector<int> condensation(vector<vector<Edge>> &g) {
  int n = g.size();
  vector<vector<Edge>> r_g(n);
  for (auto &i : g)
    for (auto &j : i)
      r_g[j.to].push_back({j.to, j.from, j.weight});
  vector<int> o;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++)
    if (!used[i])
      top_sort(i, g, used, o);
  reverse(o.begin(), o.end());

  vector<int> color(n, -1);
  int count = 0;
  for (int i = 0; i < n; i++)
    if (color[o[i]] == -1)
      dfs(o[i], r_g, color, count++);
  return color;
}

bool isConnected(vector<vector<Edge>> &v, int start) {
  int n = v.size();
  vector<bool> used(n, false);
  function<void(vector<vector<Edge>> &, int)> dfs = [&](vector<vector<Edge>> &g, int f) {
    if (used[f])
      return;
    used[f] = true;
    for (auto &t : g[f])
      dfs(g, t.to);
  };
  dfs(v, start);
  for (auto b : used)
    if (!b)
      return false;
  return true;
}

long long findMst(vector<vector<Edge>> &g, int start) {
  int n = g.size();
  long long res = 0;
  vector<int> minn(n, INF);
  for (auto &i : g)
    for (auto &j : i)
      minn[j.to] = min(minn[j.to], j.weight);
  for (int i = 0; i < n; i++)
    if (i != start)
      res += minn[i];
  vector<vector<Edge>> nullG(n);
  for (auto &i : g)
    for (auto &j : i)
      if (minn[j.to] == j.weight)
        nullG[j.from].push_back({j.from, j.to, 0});
  if (isConnected(nullG, start))
    return res;
  vector<int> components = condensation(nullG);
  int maxx = 0;
  for (int i : components)
    maxx = max(maxx, i);
  vector<vector<Edge>> new_g(maxx + 1);
  for (auto &i : g)
    for (auto &j : i)
      if (components[j.from] != components[j.to])
        new_g[components[j.from]].push_back({components[j.from], components[j.to], j.weight - minn[j.to]});
  res += findMst(new_g, components[start]);
  return res;
}

int main() {

  freopen("chinese.in", "r", stdin);
  freopen("chinese.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({a, b, c});
  }
  if (!isConnected(g, 0)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n" << findMst(g, 0) << '\n';

  return 0;
}
