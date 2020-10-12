#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

int rand(int a) {
    return ((rand() << 16) | rand()) % a;
}

void quicksort(veci &a, int l, int r) {
    int k = a[l + rand(r - l + 1)];
    int it_l = l;
    int it_r = r;
    while (it_l <= it_r) {
        while (a[it_l] < k)
            it_l++;
        while (a[it_r] > k)
            it_r--;
        if (it_l <= it_r) {
            swap(a[it_l], a[it_r]);
            it_l++;
            it_r--;
        }
    }
    if (l < it_r)
        quicksort(a, l, it_r);
    if (it_l < r)
        quicksort(a, it_l, r);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int n;
    cin >> n;
    veci a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}