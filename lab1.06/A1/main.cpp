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

template <typename T>
class Node_set {
 public:
  Node_set(T key, int index) : key(key), index(index), is_deleted(false) {
    key_hash = int(hash<T>{}(key));
  }
  int get_key_hash() { return key_hash; }
  T get_key() { return key; }
  int get_index() { return index; }
  bool get_is_deleted() { return is_deleted; }
  void set_is_deleted(bool is_deleted) { this->is_deleted = is_deleted; }
  bool compare(T other, int other_hash) {
    if (other_hash != key_hash) return false;
    if (other != key) return false;
    return true;
  }

 private:
  T key;
  int key_hash;
  int index;
  bool is_deleted;
};

template <typename T>
class Hash_set {
 public:
  Hash_set(int p) : m(4), p(p), len(0) {
    hash_table.assign(m, nullptr);
    hash_const = {random(p), random(p), random(p), random(p)};
  };
  Hash_set(){};
  void insert(T key);
  void erase(T key);
  bool exist(T key);
  int size() { return len; }

 private:
  vector<Node_set<T>*> hash_table;
  vector<int> hash_const;
  int m;
  int p;
  int len;
  int hash_function(int a, int b, int key);
  int get_index(int key, int i);
};

template <typename T>
int Hash_set<T>::hash_function(int a, int b, int key) {
  return abs(a * 1ll * key + b) % p;
}

template <typename T>
int Hash_set<T>::get_index(int key, int i) {
  return (hash_function(hash_const[0] + 1, hash_const[1], key) +
          i * 1ll * (hash_function(hash_const[2] + 1, hash_const[3], key) | 1));
}

template <typename T>
void Hash_set<T>::insert(T key) {
  int key_hash = int(hash<T>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j % m] == nullptr || hash_table[j % m]->get_is_deleted()) {
      Node_set<T>* new_node = new Node_set<T>(key, j);
      hash_table[j % m] = new_node;
      len++;
      if (len * 2 >= m) {
        vector<Node_set<T>*> add_size_hash_table(m, nullptr);
        vector<bool> add_size_is_deleted(m, false);
        hash_table.insert(hash_table.end(), all(add_size_hash_table));
        m *= 2;
        for (int k = 0; k < m; k++) {
          if () }
      }
      return;
    }

    if (hash_table[j % m]->compare(key, key_hash) && !hash_table[j % m].get_is_deleted()) return;
  }
}

template <typename T>
void Hash_set<T>::erase(T key) {
  int key_hash = int(hash<T>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j % m] == nullptr) return;
    if (hash_table[j % m]->compare(key, key_hash) && !is_deleted[j % m]) {
      is_deleted[j % m] = true;
      len--;
      return;
    }
  }
}

template <typename T>
bool Hash_set<T>::exist(T key) {
  int key_hash = int(hash<T>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j % m] == nullptr) return false;
    if (hash_table[j % m]->compare(key, key_hash) && !is_deleted[j % m])
      return true;
  }
  return false;
}

int main() {
  // freopen("set.in", "r", stdin);
  // freopen("set.out", "w", stdout);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_set<int> hash_set(1e9 + 7);
  string command;
  while (cin >> command) {
    int value;
    cin >> value;
    if (command[0] == 'i')
      hash_set.insert(value);
    else if (command[0] == 'd')
      hash_set.erase(value);
    else
      cout << (hash_set.exist(value) ? "true" : "false") << endl;
  }

  return 0;
}