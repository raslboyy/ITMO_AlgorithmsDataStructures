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

class Stack
{
public:
    Stack()
    {
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
        n--;
    }
    int top()
    {
        return array[n - 1];
    }
    int size()
    {
        return n;
    }

private:
    int n;
    veci array;
};

int main()
{
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Stack st;
    string str;
    while (cin >> str)
    {
         if (str[0] == 'l')
            break;
        if (str[0] == '+' || str[0] == '-' || str[0] == '*'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (str[0] == '+')
                st.push(a + b);
            else if (str[0] == '-')
                st.push(b - a);
            else
                st.push(a * b);
        }
        else
            st.push(stoi(str));
    }
       
    cout << st.top() << endl;

    return 0;
}