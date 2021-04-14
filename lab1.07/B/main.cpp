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

struct Node {
  int l;
  int r;
  int key;
  int i;
};

int main() {
  freopen("rotation.in", "r", stdin);
  freopen("rotation.out", "w", stdout);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int root = 0;
  vector<Node> tree(n + 1);
  vector<bool> is_root(n + 1, true);
  for (int i = 1; i <= n; i++) {
    cin >> tree[i].key >> tree[i].l >> tree[i].r;
    is_root[tree[i].l] = false;
    is_root[tree[i].r] = false;
  }

  for (int i = 1; i <= n; i++)
    if (is_root[i])
      root = i;

  vector<int> height(n + 1);

  function<void(int)> foo = [&](int v) {
    if (v == 0)
      return;
    int l = tree[v].l;
    int r = tree[v].r;
    foo(l);
    foo(r);
    height[v] = max(height[l], height[r]) + 1;
  };
  foo(root);

  function<void(int, int &)> for_print = [&](int v, int &i) {
    if (v == 0)
      return;
    tree[v].i = i++;
    for_print(tree[v].l, i);
    for_print(tree[v].r, i);
  };
  function<void(int)> print = [&](int v) {
    if (v == 0)
      return;
    cout << tree[v].key << " " << tree[tree[v].l].i << " " << tree[tree[v].r].i << '\n';
    print(tree[v].l);
    print(tree[v].r);
  };
  int a = root;
  int b = tree[root].r;
  cout << n << '\n';
  if (height[tree[b].l] - height[tree[b].r] != 1) {
    tree[a].r = tree[b].l;
    tree[b].l = a;
    int count = 1;
    for_print(b, count);
    print(b);
  } else {
    int c = tree[b].l;
    tree[b].l = tree[c].r;
    tree[c].r = b;
    tree[a].r = tree[c].l;
    tree[c].l = a;
    int count = 1;
    for_print(c, count);
    print(c);
  }


  return 0;
}