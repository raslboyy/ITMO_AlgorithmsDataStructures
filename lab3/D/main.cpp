#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <set>
#include <string>

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
        tree.assign(1e6 + 1, {0, 0});
        array.assign(1e6 + 1, 0);
    }

    void push(int a, int key) {
        tree[n] = {a, key};
        array[key] = n;
        count++;
        n++;
        up(n - 1);
    }

    int get_min() {
        return tree[0].x;
    }

    int extract_min() {
        int res = tree[0].x;
        erase_min();
        return res;
    }

    bool empty() {
        return n == 0;
    }

    void modify(int i, int new_val){
        tree[array[i]].x = new_val;
        up(array[i]);
    }

    //int size() { return n; };
private:
    void erase_min() {
        tree[0] = tree[n - 1];
        array[tree[0].y] = 0;
        n--;
        down(0);
    }

    void up(int i) {
        while (i > 0 && tree[i] < tree[(i - 1) / 2]) {
            swap(tree[i], tree[(i - 1) / 2]);
            array[tree[(i - 1) / 2].y] = (i - 1) / 2;
            array[tree[i].y] = i;
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
            swap(tree[i], tree[k]);
            array[tree[i].y] = i;
            array[tree[k].y] = k;
            i = k;
        }
    }

    int count = 0;
    vector<pi> tree;
    vector<int> array;
    int n = 0;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);

    string str;
    int count = 1;
    BinaryHeap binaryHeap;
    vector<pi> countString;
    while (cin >> str) {
        if (str[0] == 'p') {
            int a;
            cin >> a;
            binaryHeap.push(a, count);
            countString.emplace_back(mp(count, a));
        } else if (str[0] == 'e') {
            if (binaryHeap.empty())
                cout << "*" << endl;
            else
                cout << binaryHeap.extract_min() << endl;
        } else if (str[0] == 'd') {
            int a, b;
            cin >> a >> b;
            int i = lower_bound(all(countString), mp(a, 0)) - countString.begin();
            binaryHeap.modify(countString[i].x, b);
        }
        count++;
    }

    return 0;
}