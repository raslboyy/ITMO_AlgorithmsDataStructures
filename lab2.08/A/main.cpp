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
  vector<vector<bool>> matrix(n, vector<bool>(n, false));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    matrix[--a][--b] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << (matrix[i][j] ? 1 : 0) << ' ';
    cout << '\n';
  }
  return 0;
}
