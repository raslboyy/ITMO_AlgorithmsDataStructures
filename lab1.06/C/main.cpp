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

class Node {
 public:
  Node(string key, string value)
      : key(key), value(value), prev(nullptr), next(nullptr) {
    key_hash = int(hash<string>{}(key));
  }
  int get_key_hash() { return key_hash; }
  string get_key() { return key; }
  string get_value() { return value; }
  void set_value(string value) { this->value = value; }
  void set_prev(Node* prev) { this->prev = prev; }
  Node* get_prev() { return prev; }
  void set_next(Node* next) { this->next = next; }
  Node* get_next() { return next; }

 private:
  string key;
  string value;
  int key_hash;
  Node* prev;
  Node* next;
};

class Hash_map {
 public:
  Hash_map(int m, int p) : m(m), p(p) {
    hash_table.assign(m, nullptr);
    is_deleted.assign(m, false);
    hash_const = {random(p), random(p), random(p), random(p)};
    last = nullptr;
  };
  Hash_map(int p) : p(p){};
  void insert(string key, string value);
  void erase(string key);
  string get(string key);
  string prev(string key);
  string next(string key);

 private:
  vector<Node*> hash_table;
  vector<bool> is_deleted;
  vector<int> hash_const;
  Node* last;
  int m;
  int p;
  int hash_function(int a, int b, int key);
  int get_index(int key, int i);
};

int Hash_map::hash_function(int a, int b, int key) {
  return abs(a * 1ll * key + b) % p;
}

int Hash_map::get_index(int key, int i) {
  return (hash_function(hash_const[0] + 1, hash_const[1], key) +
          i * 1ll *
              (hash_function(hash_const[2] + 1, hash_const[3], key) % m)) %
         m;
}

void Hash_map::insert(string key, string value) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (is_deleted[j] || hash_table[j] == nullptr) {
      Node* new_node = new Node(key, value);
      if (last == nullptr)
        last = new_node;
      else {
        last->set_next(new_node);
        new_node->set_prev(last);
        last = new_node;
      }
      hash_table[j] = new_node;
      if (is_deleted[j])
        is_deleted[j] = false;
      return;
    }
    if (hash_table[j]->get_key() == key && !is_deleted[j]) {
      hash_table[j]->set_value(value);
      return;
    }
  }
}

void Hash_map::erase(string key) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j] == nullptr) return;
    if (hash_table[j]->get_key() == key && !is_deleted[j]) {
      if (hash_table[j] == last){
        if (hash_table[j]->get_prev() != nullptr)
          last = hash_table[j]->get_prev();
        else
          last = nullptr;
      }
      if (hash_table[j]->get_prev() != nullptr)
        hash_table[j]->get_prev()->set_next(hash_table[j]->get_next());
      if (hash_table[j]->get_next() != nullptr)
        hash_table[j]->get_next()->set_prev(hash_table[j]->get_prev());
      is_deleted[j] = true;
      return;
    }
  }
}

string Hash_map::get(string key) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j] == nullptr) return "none";
    if (hash_table[j]->get_key() == key && !is_deleted[j]) return hash_table[j]->get_value();
  }
  return "none";
}

string Hash_map::next(string key) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j] == nullptr) return "none";
    if (hash_table[j]->get_key() == key && !is_deleted[j]) {
      if (hash_table[j]->get_next() == nullptr) return "none";
      return hash_table[j]->get_next()->get_value();
    }
  }
  return "none";
}

string Hash_map::prev(string key) {
  int key_hash = int(hash<string>{}(key));
  for (int i = 0, j = get_index(key_hash, i); i < m;
       j = get_index(key_hash, ++i)) {
    if (hash_table[j] == nullptr) return "none";
    if (hash_table[j]->get_key() == key && !is_deleted[j]) {
      if (hash_table[j]->get_prev() == nullptr) return "none";
      return hash_table[j]->get_prev()->get_value();
    }
  }
  return "none";
}

int main() {
  freopen("linkedmap.in", "r", stdin);
  freopen("linkedmap.out", "w", stdout);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_map hash_map(3 * 1e5 + 7, 1e9 + 7);
  string command;
  while (cin >> command) {
    string key;
    cin >> key;
    if (command == "put") {
      string value;
      cin >> value;
      hash_map.insert(key, value);
    } else if (command == "delete")
      hash_map.erase(key);
    else if (command == "get")
      cout << hash_map.get(key) << '\n';
    else if (command == "next")
      cout << hash_map.next(key) << '\n';
    else
      cout << hash_map.prev(key) << '\n';
  }

  return 0;
}