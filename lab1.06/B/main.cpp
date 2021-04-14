#include <bits/stdc++.h>

#include <iostream>
#include <string>

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

int rand(int a, int b) { return a + (((rand() << 15) | rand()) % (b - a + 1)); }

class Hash_map {
 public:
  Hash_map(int max_value, int max_n)
      : max_value(max_value),
        max_n(max_n),
        a1(rand(1, max_value)),
        b1(rand(1, max_value)),
        a0(rand(0, max_value)),
        b0(rand(0, max_value)) {
    hash_table.assign(max_n, mp(INT_MAX, mp("none", "none")));
  };

  void put(string key, string value);
  void erase(string key);
  string get(string key);

 private:
  vector<pair<int, pair<string, string>>> hash_table;
  size_t max_value = 0;
  int a1 = 0, a0 = 0, b1 = 0, b0 = 0;
  int max_n = 0;

  int hash_function(int a, int b, int value);
  int hash_function(int k, int i);
  int string_to_int(string a);
};

int Hash_map::hash_function(int a, int b, int value) {
  return (abs(a * 1ll * value + b) % max_value) % max_n;
}

int Hash_map::hash_function(int k, int i) {
  return ((ll)hash_function(a1, a0, k) +
          i * 1ll * (hash_function(b1, b0, k) % max_n)) %
         max_n;
}

void Hash_map::put(string key, string value) {
  int key_hash = (hash<string>{}(key)) % max_value;
  for (int i = 0, j = hash_function(key_hash, i); i < max_n;
       i++, j = hash_function(key_hash, i))
    if (hash_table[j].x == INT_MAX || hash_table[j].x == INT_MIN ||
        (hash_table[j].y.x == key && hash_table[j].x != INT_MIN)) {
      hash_table[j] = mp(key_hash, mp(key, value));
      break;
    }
}

string Hash_map::get(string key) {
  int key_hash = (hash<string>{}(key)) % max_value;
  for (int i = 0, j = hash_function(key_hash, i); i < max_n;
       i++, j = hash_function(key_hash, i)) {
    if (hash_table[j].x == INT_MAX) return "none";
    if (hash_table[j].y.x == key && hash_table[j].x != INT_MIN) return hash_table[j].y.y;
  }
  return "none";
}

void Hash_map::erase(string key) {
  int key_hash = (hash<string>{}(key)) % max_value;
  for (int i = 0, j = hash_function(key_hash, i); i < max_n;
       i++, j = hash_function(key_hash, i)) {
    if (hash_table[j].x == INT_MAX) return;
    if (hash_table[j].y.x == key) {
      hash_table[j].x = INT_MIN;
      return;
    }
  }
}

int main() {
  freopen("map.in", "r", stdin);
  freopen("map.out", "w", stdout);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_map hash_map(1e9, 3 * 1e5 + 7);
  string command;
  while (cin >> command) {
    string key;
    cin >> key;
    if (command[0] == 'p') {
      string value;
      cin >> value;
      hash_map.put(key, value);
    } else if (command[0] == 'd')
      hash_map.erase(key);
    else
      cout << hash_map.get(key) << endl;
  }

  return 0;
}