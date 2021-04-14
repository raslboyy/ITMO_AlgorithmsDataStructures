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

int rand(int a, int b) { return a + ((rand() << 15) | rand()) % (b - a + 1); }

class Hash_map {
 public:
  Hash_map(int max_value, int max_n)
      : max_value(max_value),
        max_n(max_n),
        a1(rand(1, max_value)),
        b1(rand(1, max_value)),
        a0(rand(0, max_value)),
        b0(rand(0, max_value)) {
    hash_table.assign(max_n, mp(INT_MAX, ""));
  };

  void put(string key, string value);
  void erase(string key);
  string get(string key);

 private:
  vector<pair<int, string>> hash_table;
  size_t max_value = 0;
  int a1 = 0, a0 = 0, b1 = 0, b0 = 0;
  int max_n = 0;

  int hash_function(int a, int b, int value);
  int hash_function(int k, int i);
};

int Hash_map::hash_function(int a, int b, int value) {
  return ((a * 1ll * value + b) % max_value) % max_n;
}

int Hash_map::hash_function(int k, int i) {
  return ((ll)hash_function(a1, a0, k) + i * 1ll * (hash_function(b1, b0, k) % max_n)) % max_n;
}

void Hash_map::put(string key, string value) {
  int key_hash = (hash<string>{}(key)) % max_value;
  for (int i = 0, j = hash_function(key_hash, i); i < max_n; i++, j = hash_function(key_hash, i))
    if (hash_table[j].x == INT_MAX || hash_table[j].x == INT_MIN || hash_table[j].x == key_hash) {
      hash_table[j] = mp(key_hash, value);
      break;
    }
}

string Hash_map::get(string key) {
  int key_hash = (hash<string>{}(key)) % max_value;
  for (int i = 0, j = hash_function(key_hash, i); i < max_n; i++, j = hash_function(key_hash, i)) {
    if (hash_table[j].x == INT_MAX) return "none";
    if (hash_table[j].x == key_hash) return hash_table[j].y;
  }
  return "none";
}

void Hash_map::erase(string key) {
  if (get(key) == "none") return;
  int key_hash = (hash<string>{}(key)) % max_value;
  for (int i = 0, j = hash_function(key_hash, i); i < max_n; i++, j = hash_function(key_hash, i))
    if (hash_table[j].x == key_hash) {
      hash_table[j].x = INT_MIN;
      return;
    }
}

string random_string()
{
     string str("0123456789ABCDEsdfgdsgdsfhdsfgfsgdsghsdfgdsfgdsg546345trg456ytegrf435trgfdFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

     random_device rd;
     mt19937 generator(rd());

     shuffle(str.begin(), str.end(), generator);

     return str.substr(0, rand(20, 32));    // assumes 32 < number of characters in str         
}

int main() {
  // freopen("map.in", "r", stdin);
  // freopen("map.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_map hash_map(1e9, 3 * 1e5 + 7);
  map<string, string> map;
  int t = 1e6;
  while (t--) {
    string key = random_string();
    int command = rand(0, 2);
    if (command == 0) {
      string value = random_string();
      hash_map.put(key, value);
      map[key] = value;
    } else if (command == 1){
      hash_map.erase(key);
      map.erase(key);
    }
    else {
      if (map[key] != hash_map.get(key))
        cout << key << endl;
    }
  }

  return 0;
}