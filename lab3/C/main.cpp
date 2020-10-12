#include <iostream>
#include <vector>
#include <list>

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
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++) {
        vector<list<string>> b(300);
        for (int j = 0; j < n; j++)
            b[a[j][m - i - 1]].emplace_back(a[j]);
        for (int j = 0, it = 0; j < 300; j++)
            while (!b[j].empty()){
                a[it] = b[j].front();
                it++;
                b[j].pop_front();
            }
    }
    for (string str : a)
        cout << str << '\n';


    return 0;
}