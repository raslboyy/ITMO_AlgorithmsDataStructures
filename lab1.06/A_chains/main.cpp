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

template <typename T>
class Node_set {
 public:
  Node_set(T key) : key(key) { key_hash = int(hash<T>{}(key)); };
  T get_key() { return key; }
  int get_key_hash() { return key_hash; }

 private:
  T key;
  int key_hash;
};

template <typename T>
class Hash_set {
 public:
  Hash_set(int p) : p(p) {
    m = 2;
    hash_table.assign(m, list<Node_set<T>*>());
    random_const = {random(p), random(p), random(p), random(p)};
  }
  void insert(T key);
  void erase(T key);
  bool exist(T key);

 private:
  vector<list<Node_set<T>*>> hash_table;
  vector<int> random_const;
  int m;
  int p;
  int len;
  int hash_function(int a, int b, T key);
};

template <typename T>
int Hash_set<T>::hash_function(int a, int b, T key) {
  return abs(a * 1ll * int(hash<T>{}(key)) + b) % p;
}

template <typename T>
void Hash_set<T>::insert(T key) {
  if (exist(key))
    return;
  int key_hash = hash_function(random_const[0] + 1, random_const[1], key);
  hash_table[key_hash % m].emplace_back(new Node_set<T>(key));
  len++;
  if (len * 2 >= m) {
    vector<list<Node_set<T>*>> new_hash_table(2*m, list<Node_set<T>*>());
    for (int i = 0; i < m; i++)
      for (auto j : hash_table[i])
        new_hash_table[hash_function(random_const[0] + 1, random_const[1], j->get_key()) % (2 * m)].emplace_back(j);
    hash_table = new_hash_table;
    m *= 2;
  }
}

template <typename T>
void Hash_set<T>::erase(T key) {
  int key_hash = hash_function(random_const[0] + 1, random_const[1], key);
  for (auto it = hash_table[key_hash % m].begin(); it != hash_table[key_hash % m].end(); it++)
    if ((*it)->get_key() == key) {
      hash_table[key_hash % m].erase(it);
      len--;
      break;
    }
}

template <typename T>
bool Hash_set<T>::exist(T key) {
  int key_hash = hash_function(random_const[0] + 1, random_const[1], key);
  for (auto it = hash_table[key_hash % m].begin(); it != hash_table[key_hash % m].end(); it++)
    if ((*it)->get_key() == key)
      return true;
  return false;
}

int main() {
  freopen("set.in", "r", stdin);
  freopen("set.out", "w", stdout);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Hash_set<string> hash_set(1e9 + 7);
  string command;
  while (cin >> command) {
    string value;
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