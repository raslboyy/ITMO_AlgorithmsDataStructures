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

int lower(veci &a, int value)
{
    value--;
    int l = 0, r = sz(a);
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] <= value)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int upper(veci &a, int value)
{
    int l = 0, r = sz(a);
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] <= value)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    veci a(n+2);
    a[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n+1] = INT_MAX;

    int t;
    cin >> t;
    while (t--)
    {
        int value;
        cin >> value;
        int l = lower(a, value);
        int r = upper(a, value);
        if (l > r)
            cout << "-1 -1\n";
        else
            cout << l << ' ' << r << '\n';
    }

    return 0;
}