#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    BinaryHeap() {
        tree.assign(1e6 + 1, 0);
    }

    void push(int a) {
        tree[n] = a;
        M[a].emplace(n);
        n++;
        up(n - 1);
    }

    int extract_min() {
        if (n == 0)
            return INT_MAX;
        int res = tree[0];
        erase_min();
        return res;
    }

    void decrease_key(int key, int a) {
        int i = *M[key].begin();
        M[key].erase(i);
        M[a].emplace(i);
        tree[i] = a;
        up(i);
    }

    void print(){
        for (int i = 0; i < n; i++)
            cout << tree[i] << ' ';
        cout << endl;
    }

    //int size() { return n; };
private:
    void erase_min() {
        M[tree[0]].erase(0);
        tree[0] = tree[n - 1];
        M[tree[0]].erase(n - 1);
        M[tree[0]].emplace(0);
        n--;
        down(0);
    }

    void up(int i) {
        while (i > 0 && tree[i] < tree[(i - 1) / 2]) {
            M[tree[i]].erase(i);
            M[tree[i]].emplace((i - 1) / 2);
            M[tree[(i - 1) / 2]].erase((i - 1) / 2);
            M[tree[(i - 1) / 2]].emplace(i);
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
            if (right < n && tree[right] < tree[left])
                k = right;
            if (tree[k] >= tree[i])
                break;
            M[tree[i]].erase(i);
            M[tree[i]].emplace(k);
            M[tree[k]].erase(k);
            M[tree[k]].emplace(i);
            swap(tree[i], tree[k]);
            i = k;
        }
    }

    int count = 0;
    vector<int> tree;
    int n = 0;
    unordered_map<int, unordered_set<int>> M;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int n;
    cin >> n;
    BinaryHeap binaryHeap;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        binaryHeap.push(a);
    }
    for (int i = 0; i < n; i++)
        cout << binaryHeap.extract_min() << ' ';



    return 0;
}