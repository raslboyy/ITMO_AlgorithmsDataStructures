#include <vector>
#include <functional>
#include <iostream>

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


int main() {
   freopen("balance.in", "r", stdin);
   freopen("balance.out", "w", stdout);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int root = 0;
  vector<pi> tree(n + 1);
  vector<bool> is_root(n + 1, true);
  for (int i = 1; i <= n; i++) {
    int key = 0;
    cin >> key >> tree[i].x >> tree[i].y;
    is_root[tree[i].x] = false;
    is_root[tree[i].y] = false;
  }

  for (int i = 1; i <= n; i++)
    if (is_root[i])
      root = i;

  vector<int> height(n + 1);
  function<void(int)> foo = [&](int v) {
    if (v == 0)
      return ;
    int l = tree[v].x;
    int r = tree[v].y;
    foo(l);
    foo(r);
    height[v] = max(height[l], height[r]) + 1;
  };
  foo(root);
  for (int i = 1; i <= n; i++) {
    int l = tree[i].x;
    int r = tree[i].y;
    cout << height[r] - height[l] << '\n';
  }



  return 0;
}