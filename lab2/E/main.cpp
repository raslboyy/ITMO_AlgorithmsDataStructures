#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <chrono>
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

class BinaryHeap {
public:
    BinaryHeap(veci &a) : tree(a) {
        n = sz(tree);
        for (int i = sz(tree) / 2; i >= 0; i--) {
            down(i);
        }
    }

    void add(int a) {
        tree[n] = a;
        n++;
        up(n - 1);
    }

    void erase_max() {
        tree[0] = tree[n - 1];
        n--;
        down(0);
    }

    int get_max() {
        return tree[0];
    }

    void foo(int a) {
        tree[0] = a;
        down(0);
    }

    //int size() { return n; };
private:
    void up(int i) {
        while (i > 0 && tree[i] > tree[(i - 1) / 2]) {
            swap(tree[i], tree[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void down(int i) {
        while (true) {
            int left = (i * 2) + 1;
            int right = (i * 2) + 2;
            if (left >= n)
                break;
            int k = left;
            if (right < n && tree[right] > tree[left])
                k = right;
            if (tree[k] <= tree[i])
                break;
            swap(tree[i], tree[k]);
            i = k;
        }
    }

    vector<int>& tree;
    int n = 0;
};

int foo1(int n, int k, int A, int B, int C, int a1, int a2) {
    veci array(k);
    array[0] = a1;
    if (k > 1 && n > 1)
        array[1] = a2;
    for (int i = 2; i < k; i++) {
        int a = a1 * A + a2 * B + C;
        array[i] = a;
        a1 = a2;
        a2 = a;
    }
    priority_queue<int> binaryHeap(all(array));
    if (k == 1 && n >= 2 && a2 < binaryHeap.top()) {
        binaryHeap.emplace(a2);
    }

    for (int i = max(2, k); i < n; i++) {
        int a = a1 * A + a2 * B + C;
        if (a < binaryHeap.top()) {
            binaryHeap.pop();
            binaryHeap.emplace(a);

        }
        a1 = a2;
        a2 = a;
    }
    return binaryHeap.top();
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("kth.in", "r", stdin);
    //freopen("kth.out", "w", stdout);


    int n, k, a1, a2, A, B, C;
    cin >> n >> k >> A >> B >> C >> a1 >> a2;
    auto start_time = chrono::high_resolution_clock::now();
    cout << foo1(n, k, A, B, C, a1, a2) << endl;
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;
    cout << duration.count() << "\n";

    return 0;
}