#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>

#define mp make_pair
#define pb push_back
#define eb emplace_back
//#define x first
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

int k;

int quicksort(veci &a, int l, int r) {
    int x = a[l + rand(r - l + 1)];
    int it_l = l;
    int it_r = r;
    while (it_l <= it_r) {
        while (a[it_l] < x)
            it_l++;
        while (a[it_r] > x)
            it_r--;
        if (it_l <= it_r) {
            swap(a[it_l], a[it_r]);
            it_l++;
            it_r--;
        }
    }
    if (k >= l && k <= it_r) {
        if (l < it_r)
            return quicksort(a, l, it_r);
        else
            return a[l];
    }
    if (k >= it_l && k <= r) {
        if (it_l < r)
            return quicksort(a, it_l, r);
        else
            return a[r];
    }
    return a[it_r + 1];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("kth.in", "r", stdin);
    //freopen("kth.out", "w", stdout);

    long long b;
    long long *a = &b;
    cout << sizeof(b) << endl;
    /*int n, A, B, C;
    cin >> n >> k;
    k--;
    veci a(n);
    cin >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    cout << quicksort(a, 0, n-1) << '\n';*/

    return 0;
}