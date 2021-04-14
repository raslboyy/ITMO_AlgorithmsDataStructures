#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double INF = 1e9;

struct Point {
  int x;
  int y;
};

double len(Point a, Point b) {
  return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {

  freopen("spantree.in", "r", stdin);
  freopen("spantree.out", "w", stdout);
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; i++)
    cin >> points[i].x >> points[i].y;
  vector<vector<double>> g(n, vector<double>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i != j)
        g[i][j] = len(points[i], points[j]);
      else
        g[i][j] = INF;
    }
  vector<bool> used(n, false);
  vector<double> min_e(n, INF);
  min_e[0] = 0;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int j = 0; j < n; j++)
      if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
        v = j;
    sum += min_e[v];
    used[v] = true;
    for (int j = 0; j < n; j++)
      min_e[j] = min(min_e[j], g[v][j]);
  }
  cout << fixed << sum << '\n';

  return 0;
}
