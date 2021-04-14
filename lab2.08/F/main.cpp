#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main() {
//  freopen("pathbge1.in", "r", stdin);
//  freopen("pathbge1.out", "w", stdout);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<bool>> matrix(n, vector<bool>(m, true));
  pair<int, int> s, t;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if (ch == '#')
        matrix[i][j] = false;
      if (ch == 'S')
        s = {i, j};
      if (ch == 'T')
        t = {i, j};
    }

  queue<pair<int, int>> q;
  vector<vector<int>> d(n, vector<int>(m, -1));
  d[s.first][s.second] = 0;
  q.push(s);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++)
        if (abs(i) + abs(j) == 1) {
          pair<int, int> to = {v.first + i, v.second + j};
          if (to.first >= 0 && to.second >= 0 && to.first < n && to.second < m)
            if (d[to.first][to.second] == -1 && matrix[to.first][to.second]) {
              d[to.first][to.second] = d[v.first][v.second] + 1;
              q.push(to);
            }
        }
  }

  if (d[t.first][t.second] == -1) {
    cout << -1 << '\n';
    return 0;
  }

  stack<char> way;
  cout << d[t.first][t.second] << '\n';
  while (t != s) {
    if (t.first > 0 && d[t.first - 1][t.second] + 1 == d[t.first][t.second]) {
      way.push('D');
      t.first--;
    }
    else if (t.first + 1 < n && d[t.first + 1][t.second] + 1 == d[t.first][t.second]) {
      way.push('U');
      t.first++;
    }
    else if (t.second > 0 && d[t.first][t.second - 1] + 1 == d[t.first][t.second]) {
      way.push('R');
      t.second--;
    }
    else if (t.second + 1 < m && d[t.first][t.second + 1] + 1 == d[t.first][t.second]) {
      way.push('L');
      t.second++;
    }
  }

  while (!way.empty()) {
    cout << way.top();
    way.pop();
  }

  return 0;
}