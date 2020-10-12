#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, b, a) for (int i = (b) - 1; i >= (a); i--)

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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);

    int n;
    cin >> n;
    veci a(1);
    a[0] = 1;
    for (int i = 0; i < n-1; i++) {
        int k = ceil((double)i / 2);
        a.eb(i + 2);
        swap(a[k], a[i + 1]);
    }

    for (int j : a)
        cout << j << ' ';
    cout << '\n';

    return 0;
}