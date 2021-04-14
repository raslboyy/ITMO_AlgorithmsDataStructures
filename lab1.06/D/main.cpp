#include <bits/stdc++.h>

#include <iostream>

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

int random(int mod) { return ((rand() << 15) | rand()) % mod; }

class Node_set {
 public:
  Node_set(string key) : key(key) { key_hash = int(hash<string>{}(key)); }
  int get_key_hash() { return key_hash; }
  string get_key() { return key; }
  bool compare(string other, int other_hash) {
    if (other_hash != key_hash) return false;
    if (other != key) return false;
    return true;
  }

 private:
  string key;
  int key_hash;
};

class Hash_set {
 public:
  Hash_set(int p) : m(4), p(p), len(0) {
    hash_table.assign(m, nullptr);
    is_deleted.assign(m, false);
    hash_const = {random(p), random(p), random(p), random(p)};
  };
  Hash_set(int p) : p(p){};
  Hash_set(){};
  void insert(string key);
  void erase(string key);
  int size() { return len; }

 private:
  vector<Node_set*> hash_table;
  vector<bool> is_deleted;
  vector<int> hash_const;
  int m;
  int p;
  int len;
  int hash_function(int a, int b, int key);
  int get_index(int key, int i);
};

int Hash_set::hash_function(int a, int b, int key) {
  return abs(a * 1ll * key + b) % p;
}

int Hash_set::get_index(int key, int i) {
  return (hash_function(hash_const[0] + 1, hash_const[1], key) +
          i * 1ll *
              (hash_function(hash_const[2] + 1, hash_const[3], key) | 1)) %
         m;
}

void Hash_set::insert(string key) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (is_deleted[j] || hash_table[j] == nullptr) {
      Node_set* new_node = new Node_set(key);
      hash_table[j] = new_node;
      is_deleted[j] = false;
      len++;
      if (len * 2 >= m){
        vector<Node_set*> new_memory(m, nullptr);
        hash_table.insert(hash_table.end(), all(new_memory));
        m *= 2;
      }
      return;
    }
    if (hash_table[j]->compare(key, key_hash) && !is_deleted[j]) return;
  }
}

void Hash_set::erase(string key) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j] == nullptr) return;
    if (hash_table[j]->compare(key, key_hash) && !is_deleted[j]) {
      is_deleted[j] = true;
      len--;
      return;
    }
  }
}

class Node_map {
 public:
  Node_map(string key, int m, int p) : key(key), m(m), p(p) {
    value_set = Hash_set(m, p);
  }

 private:
  string key;
  int m;
  int p;
  Hash_set value_set;
};

int main() {
  // freopen("linkedmap.in", "r", stdin);
  // freopen("linkedmap.out", "w", stdout);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_set Hash_set(3 * 1e5 + 7, 1e9 + 7);
  string command;
  while (cin >> command) {
    string key;
    cin >> key;
    if (command == "put") {
      string value;
      cin >> value;
      Hash_set.insert(key, value);
    } else if (command == "delete")
      Hash_set.erase(key);
    else if (command == "get")
      cout << Hash_set.get(key) << '\n';
    else if (command == "next")
      cout << Hash_set.next(key) << '\n';
    else
      cout << Hash_set.prev(key) << '\n';
  }

  return 0;
}