#include <iostream>
#include <vector>
#include <list>
#include <bitset>

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
    //freopen("isheap.in", "r", stdin);
    //freopen("isheap.out", "w", stdout);

    int16_t a = 15452;
    int16_t b = 17458;
    bitset<16> bin(a + b);
    cout << bin.to_string() << endl;
    bin[15] = false;
    cout << bin << endl;

    int n;
    cin >> n;
    veci a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i << 1 <= n && a[i << 1] < a[i]) {
            cout << "NO\n";
            return 0;
        }
        if ((i << 1) + 1 <= n && a[(i << 1) + 1] < a[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}