#include <iostream>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(n));
  bool flag = true;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (matrix[a][b] == 1 || matrix[b][a] == 1)
      flag = false;
    matrix[a][b]++;
    matrix[b][a]++;
  }
  if (!flag) {
    cout << "YES\n";
    return 0;
  }

  cout << "NO\n";

  return 0;
}
