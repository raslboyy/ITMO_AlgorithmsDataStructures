#include <iostream>
#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ef emplace_back
#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); i--)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pl;
typedef vector<int> veci;
typedef vector<bool> vecb;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

const int INF_I = 1e9;
const ll INF_LL = 1e18;
const int MOD = 1000000007;
const double eps = 1e-6;
//(clock() * 1.0 / CLOCKS_PER_SEC)

vvi tree;

void dfs(int v, int l, int r){
  if (tree[v][0] <= l || tree[v][0] >= r){
    cout << "NO\n";
    exit(0);
  }
  if (tree[v][1] != -1)
    dfs(tree[v][1], l, tree[v][0]);
  if (tree[v][2] != -1)
    dfs(tree[v][2], tree[v][0], r);
}

int main() {
   freopen("check.in", "r", stdin);
   freopen("check.out", "w", stdout);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  if (n == 0){
    cout << "YES\n";
    return 0;
  }
  
  tree.assign(n, veci(3));
  for (int i = 0; i < n; i++){
    cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    tree[i][1]--, tree[i][2]--;
  }
  
  vecb u(n);
  for (int i = 0; i < n; i++){
    if (tree[i][1] != -1)
      u[tree[i][1]] = true;
    if (tree[i][2] != -1)
      u[tree[i][2]] = true;
  }

  for (int i = 0; i < n; i++)
    if (!u[i]){
      dfs(i, INT_MIN, INT_MAX);
      break;
    }
  cout << "YES\n";

  return 0;
}