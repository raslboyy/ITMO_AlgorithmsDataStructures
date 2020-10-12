#include <iostream>
#include <bits/stdc++.h>
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
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)

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

template <typename T>
int partition(vector<T>& a, int l, int r){
    int mid = (l + r) / 2;
    int i = l;
    int j = r;
    while (i <= j){
        while (a[i] < a[mid])
            i++;
        while (a[j] > a[mid])
            j--;
        if (i <= j)
            swap(a[i++], a[j--]);
    }
    return j;
}

template <typename T>
void quick_sort(vector<T>& a, int l, int r){
    if (l >= r)
        return;
    int mid = partition(a, l, r);
    quick_sort(a, l, mid - 1);
    quick_sort(a, mid + 1, r);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("smallsort.in", "r", stdin);
    //freopen("smallsort.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<double, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].x;
        a[i].y = i + 1;
    }

    quick_sort(a, 0, n-1);

    cout << a[0].y << ' ' << a[n/2].y << ' ' << a[n-1].y << '\n';

    return 0;
}