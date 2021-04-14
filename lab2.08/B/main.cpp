#include <iostream>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];

  for (int i = 0; i < n; i++)
    if (matrix[i][i]) {
      cout << "NO\n";
      return 0;
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (matrix[i][j] != matrix[j][i]) {
        cout << "NO\n";
        return 0;
      }

  cout << "YES\n";

  return 0;
}
