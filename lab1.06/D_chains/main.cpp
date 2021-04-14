#include <vector>
#include <list>
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

template<typename T>
class Node_set {
 public:
  Node_set(T key) : key(key) {
    key_hash = hash<T>{}(key);
  };
  T get_key() { return key; }
  int get_key_hash() { return key_hash; }

 private:
  T key;
  int key_hash;
};

template<typename T>
class Hash_set {
 public:
  Hash_set(int p) : p(p) {
    m = 2;
    len = 0;
    hash_table.assign(m, list<Node_set<T> *>());
    random_const = {random(p), random(p), random(p), random(p)};
  }
  void insert(T key);
  void erase(T key);
  bool exist(T key);
  int size() { return len; }
  void print();

 private:
  vector<list<Node_set<T> *>> hash_table;
  vector<int> random_const;
  int m;
  int p;
  int len;
  int hash_function(int a, int b, T key);
};

template<typename T>
void Hash_set<T>::print() {
  cout << len << ' ';
  for (int i = 0; i < m; i++)
    for (auto j : hash_table[i])
      cout << j->get_key() << ' ';
  cout << '\n';
}

template<typename T>
int Hash_set<T>::hash_function(int a, int b, T key) {
  return abs(a * 1ll * int(hash<T>{}(key)) + b) % p;
}

template<typename T>
void Hash_set<T>::insert(T key) {
  if (exist(key))
    return;
  int key_hash = hash_function(random_const[0] + 1, random_const[1], key);
  hash_table[key_hash % m].emplace_back(new Node_set<T>(key));
  len++;
  if (len >= 100*m) {
    vector<list<Node_set<T> *>> new_hash_table(2 * m, list<Node_set<T> *>());
    for (int i = 0; i < m; i++)
      for (auto j : hash_table[i])
        new_hash_table[hash_function(random_const[0] + 1, random_const[1], j->get_key()) % (2 * m)].emplace_back(j);
    hash_table = new_hash_table;
    m *= 2;
  }
}

template<typename T>
void Hash_set<T>::erase(T key) {
  int key_hash = hash_function(random_const[0] + 1, random_const[1], key);
  int T_hash = hash<T>{}(key);
  for (auto it = hash_table[key_hash % m].begin(); it != hash_table[key_hash % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == key) {
      hash_table[key_hash % m].erase(it);
      len--;
      break;
    }
}

template<typename T>
bool Hash_set<T>::exist(T key) {
  int key_hash = hash_function(random_const[0] + 1, random_const[1], key);
  int T_hash = hash<T>{}(key);
  for (auto it = hash_table[key_hash % m].begin(); it != hash_table[key_hash % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == key)
      return true;
  return false;
}

template<typename T>
class Node_map {
 public:
  Node_map(T key, int p) : key(key) {
    hash_set = new Hash_set<T>(p);
    key_hash = hash<T>{}(key);
  }
  T get_key() { return key; }
  int get_key_hash() { return key_hash; }
  bool exist(T set_key) { return hash_set->exist(set_key); }
  void insert(T set_key) { hash_set->insert(set_key); }
  void erase(T set_key) { hash_set->erase(set_key); }
  void print() { hash_set->print(); }
 private:
  T key;
  int key_hash;
  Hash_set<T> *hash_set;
};

template<typename T>
class Hash_map {
 public:
  Hash_map(int p, int m) : p(p), m(m) {
    hash_table.assign(m, list<Node_map<T> *>());
    random_const = {random(p), random(p), random(p), random(p)};
  }

  void insert(T a, T b);
  void erase(T a, T b);
  void erase(T a);
  bool exist(T a, T b);
  bool exist(T a);
  void print(T a);

 private:
  vector<list<Node_map<T> *>> hash_table;
  vector<int> random_const;
  int m;
  int p;
  int hash_function(int a, int b, T key);
};

template<typename T>
int Hash_map<T>::hash_function(int a, int b, T key) {
  return abs(a * 1ll * int(hash<T>{}(key)) + b) % p;
}

template<typename T>
void Hash_map<T>::insert(T a, T b) {
  if (exist(a, b))
    return;
  int hash_a = hash_function(random_const[0] + 1, random_const[1], a);
  int T_hash = hash<T>{}(a);
  if (!exist(a))
    hash_table[hash_a % m].emplace_back(new Node_map<T>(a, 1e6 + 7));
  for (auto it = hash_table[hash_a % m].begin(); it != hash_table[hash_a % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == a)
      (*it)->insert(b);
}

template<typename T>
void Hash_map<T>::erase(T a, T b) {
  int hash_a = hash_function(random_const[0] + 1, random_const[1], a);
  int T_hash = hash<T>{}(a);
  for (auto it = hash_table[hash_a % m].begin(); it != hash_table[hash_a % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == a)
      (*it)->erase(b);
}

template<typename T>
void Hash_map<T>::erase(T a) {
  int hash_a = hash_function(random_const[0] + 1, random_const[1], a);
  int T_hash = hash<T>{}(a);
  for (auto it = hash_table[hash_a % m].begin(); it != hash_table[hash_a % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == a) {
      hash_table[hash_a % m].erase(it);
      break;
    }
}

template<typename T>
void Hash_map<T>::print(T a) {
  int hash_a = hash_function(random_const[0] + 1, random_const[1], a);
  for (auto it = hash_table[hash_a % m].begin(); it != hash_table[hash_a % m].end(); it++)
    if ((*it)->get_key() == a) {
      (*it)->print();
      return;
    }
  cout << "0\n";
}

template<typename T>
bool Hash_map<T>::exist(T a, T b) {
  int hash_a = hash_function(random_const[0] + 1, random_const[1], a);
  int T_hash = hash<T>{}(a);
  for (auto it = hash_table[hash_a % m].begin(); it != hash_table[hash_a % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == a)
      return (*it)->exist(b);
  return false;
}

template<typename T>
bool Hash_map<T>::exist(T a) {
  int hash_a = hash_function(random_const[0] + 1, random_const[1], a);
  int T_hash = hash<T>{}(a);
  for (auto it = hash_table[hash_a % m].begin(); it != hash_table[hash_a % m].end(); it++)
    if (T_hash == (*it)->get_key_hash() && (*it)->get_key() == a)
      return true;
  return false;
}

int main() {
  freopen("multimap.in", "r", stdin);
  freopen("multimap.out", "w", stdout);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_map<string> hash_map(1e9 + 7, 3 * 1e5 + 17);
  string command;
  while (cin >> command) {
    string a;
    cin >> a;
    if (command[0] == 'p') {
      string b;
      cin >> b;
      hash_map.insert(a, b);
    } else if (command[0] == 'g')
      hash_map.print(a);
    else if (command == "delete") {
      string b;
      cin >> b;
      hash_map.erase(a, b);
    } else
      hash_map.erase(a);
  }

  return 0;
}