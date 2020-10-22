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

class Queue
{
public:
    Queue()
    {
        st = 0;
        n = 0;
    }
    void push(int value)
    {
        if (sz(array) == n)
            array.push_back(value);
        else
            array[n] = value;
        n++;
    }
    void pop()
    {
        st++;
    }
    int top()
    {
        return array[st];
    }

private:
    int n;
    int st;
    veci array;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    Queue my_queue;
    int n;
    cin >> n;
    while (n--)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int value;
            cin >> value;
            my_queue.push(value);
        }
        else
        {
            cout << my_queue.top() << '\n';
            my_queue.pop();
        }
    }

    return 0;
}