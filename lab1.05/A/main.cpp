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

int main() {
  freopen("height.in", "r", stdin);
  freopen("height.out", "w", stdout);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  if (n == 0){
    cout << "0\n";
    return 0;
  }
  veci pr(n, -1);
  for (int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    pr[--b] = i;
    pr[--c] = i;
  }

  veci depth(n, -1);
  function<void(int)> foo = [&](int v){
      if (pr[v] == -1){
        depth[v] = 1;
        return;
      }
      if (depth[pr[v]] != -1){
        depth[v] = depth[pr[v]] + 1;
        return;
      }
      foo(pr[v]);
      depth[v] = depth[pr[v]] + 1;
    };
  for (int i = 0; i < n; i++){
    int cur = i;
    foo(cur);
  }
  int maxx = 0;
  for (int i : depth)
    maxx = max(maxx, i);
  cout << maxx << endl;


  return 0;
}