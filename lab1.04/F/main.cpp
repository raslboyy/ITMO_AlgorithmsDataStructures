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

double check(double a1, double a2, int n)
{
    int count0 = 0;
    if (a2 == 0)
        count0++;
    double a3 = -a1 + 2 * a2 + 2;
    if (a3 == 0)
        count0++;
    if (count0 > 1 || a2 < 0 || a3 < 0)
        return -1;
    while (n - 3)
    {
        a1 = a2;
        a2 = a3;
        a3 = -a1 + 2 * a2 + 2;
        if (a3 == 0)
            count0++;
        if (a3 < 0 || count0 > 1)
            return -1;
        n--;
    }
    return a3;
}

int main()
{
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const double EPS = 1e-9;

    int n;
    double A;
    cin >> n >> A;
    double u = A, d = -EPS;
    double ans = 0;
    while (d + EPS < u)
    {
        double m = (d + u) / 2;
        double code = check(A, m, n);
        if (code != -1){
            u = m;
            ans = code;
        }
        else
            d = m;
    }
    cout.precision(2);
    cout << fixed << ans << '\n';

    return 0;
}