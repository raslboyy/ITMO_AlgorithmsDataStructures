
#include <iostream>
#include <vector>
#include <algorithm>
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

ll merge(vector<int> &a, int l, int m, int r) {
    ll count = 0;
    ll cur_count = 0;
    int it1 = 0;
    int it2 = 0;
    int len = r - l + 1;
    vector<int> result(len);
    while (it1 < (m - l) & it2 < (r - m + 1)) {
        if (a[l + it1] <= a[m + it2]) {
            count += cur_count;
            result[it1 + it2] = a[l + it1];
            it1++;
        } else {
            result[it1 + it2] = a[m + it2];
            it2++;
            cur_count++;
        }
    }
    while (it1 < (m - l)) {
        count += cur_count;
        result[it1 + it2] = a[l + it1];
        it1++;
    }
    while (it2 < (r - m + 1)) {
        result[it1 + it2] = a[m + it2];
        it2++;
    }
    for (int i = l; i <= r; i++)
        a[i] = result[i - l];
    return count;
}

ll merge_sort(vector<int> &a, int l, int r) {
    if (l >= r)
        return 0;
    int mid = l + (r - l + 1) / 2;
    ll count = 0;
    count += merge_sort(a, l, mid - 1);
    count += merge_sort(a, mid, r);
    return count + merge(a, l, mid, r);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << merge_sort(a, 0, n - 1) << '\n';

    return 0;
}
