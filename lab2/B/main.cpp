#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <list>
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

void merge(vector<pair<string, string>> &a, int l1, int l2, int r1, int r2) {
    int itl = 0;
    int itr = 0;
    int len = (r2 - l1 + 1);
    vector<pair<string, string>> b(len);
    while (l1 + itl <= l2 && r1 + itr <= r2) {
        if (a[l1 + itl].x <= a[r1 + itr].x) {
            b[itl + itr] = a[l1 + itl];
            itl++;
        } else {
            b[itl + itr] = a[r1 + itr];
            itr++;
        }
    }
    while (l1 + itl <= l2) {
        b[itl + itr] = a[l1 + itl];
        itl++;
    }
    while (r1 + itr <= r2) {
        b[itl + itr] = a[r1 + itr];
        itr++;
    }
    for (int i = l1; i <= r2; i++)
        a[i] = b[i - l1];
}

void merge_sort(vector<pair<string, string>> &a, int l, int r) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, m + 1, r);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<string, string>> array(n);
    for (int i = 0; i < n; i++)
        cin >> array[i].x >> array[i].y;
    merge_sort(array, 0, n-1);
    string cur = "-";
    for (int i = 0; i < n; i++){
        if (array[i].x != cur)
            cout << "=== " << array[i].x << " ===\n";
        cout << array[i].y << '\n';
        cur = array[i].x;
    }

    return 0;
}