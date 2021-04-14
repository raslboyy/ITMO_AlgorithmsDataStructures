#include <vector>
#include <functional>
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

class Node {
 public:
  Node(int key) : key(key), diff(0), num(0), l(nullptr), r(nullptr) {};
  int key;
  int diff;
  int num;
  Node *l;
  Node *r;
};

class AVL {
 public:
  AVL() : root(nullptr) {};
  AVL(vector<vector<int>>& vec);
  int insert(int key);
  int erase(int key);
  bool exist(int key);
  void print();
 private:
  Node *root;
  int size = 0;
  pair<Node *, bool> insert(int key, Node *node);
  pair<Node *, bool> erase(int key, Node *node);
  bool exist(int key, Node *node);
  void print(Node *node);
  Node *rotate(Node *a);
  Node *rotate_left(Node *a);
  Node *big_rotate_left(Node *a);
  Node *rotate_right(Node *a);
  Node *big_rotate_right(Node *a);
};

AVL::AVL(vector<vector<int>> &tree) : root(nullptr) {
  int v_root = 0;
  int n = tree.size();
  vector<bool> is_root(n, true);
  vector<int> height(n);
  for (int i = 1; i < n; i++) {
    is_root[tree[i][1]] = false;
    is_root[tree[i][2]] = false;
  }
  for (int i = 1; i < n; i++)
    if (is_root[i])
      v_root = i;
  function<void(Node*, int)> foo = [&](Node* node, int v) {
    height[v] = 0;
    int l = tree[v][1];
    int r = tree[v][2];
    if (l) {
      node->l = new Node(tree[l][0]);
      foo(node->l, l);
      height[v] = height[l];
    }
    if (r) {
      node->r = new Node(tree[r][0]);
      foo(node->r, r);
      height[v] = max(height[v], height[r]);
    }
    height[v] = max(height[l], height[r]) + 1;
    node->diff = height[l] - height[r];
  };
  if (n > 1){
    root = new Node(tree[v_root][0]);
    foo(root, v_root);
  }
}

int AVL::insert(int key) {
  if (exist(key))
    return root->diff;
  root = insert(key, root).first;
  return root->diff;
}

pair<Node *, bool> AVL::insert(int key, Node *node) {
  if (node == nullptr) {
    node = new Node(key);
    return pair(node, true);
  }
  bool flag = false;
  if (key < node->key) {
    auto result = insert(key, node->l);
    node->l = result.first;
    flag = result.second;
    if (flag)
      node->diff++;
  } else if (key > node->key) {
    auto result = insert(key, node->r);
    node->r = result.first;
    flag = result.second;
    if (flag)
      node->diff--;
  }
  if (node->diff == 0)
    return pair(node, false);
  node = rotate(node);
  if (node->diff == 0)
    flag = false;
  return pair(node, flag);
}

int AVL::erase(int key) {
  if (root == nullptr)
    return 0;
  if (!exist(key))
    return root->diff;
  root = erase(key, root).first;
  return (root == nullptr ? 0 : root->diff);
}

pair<Node *, bool> AVL::erase(int key, Node *node) {
  bool flag = true;
  if (key < node->key) {
    auto result = erase(key, node->l);
    node->l = result.first;
    flag = result.second;
    if (flag)
      node->diff--;
  } else if (key > node->key) {
    auto result = erase(key, node->r);
    node->r = result.first;
    flag = result.second;
    if (flag)
      node->diff++;
  } else {
    if (node->l != nullptr && node->r != nullptr) {
      auto v = node->l;
      while (v->r != nullptr)
        v = v->r;
      int new_value = v->key;
      auto result = erase(new_value, node->l);
      node->l = result.first;
      flag = result.second;
      if (flag)
        node->diff--;
      node->key = new_value;
    } else if (node == root) {
      root = (node->r == nullptr ? node->l : node->r);
      delete node;
      return pair(root, true);
    } else {
      auto v = (node->r == nullptr ? node->l : node->r);
      delete node;
      return pair(v, true);
    }
  }
  if (abs(node->diff) == 1)
    return pair(node, false);
  node = rotate(node);
  if (node->diff != 0)
    flag = false;
  return pair(node, flag);
}

bool AVL::exist(int key) {
  return exist(key, root);
}

bool AVL::exist(int key, Node *node) {
  if (node == nullptr)
    return false;
  if (key < node->key)
    return exist(key, node->l);
  if (key > node->key)
    return exist(key, node->r);
  return true;
}

Node *AVL::rotate(Node *a) {
  int d = a->diff;
  if (d == -2) {
    Node *b = a->r;
    if (b->diff == 1) {
      Node *c = b->l;
      if (c->diff == 1)
        a->diff = 0, b->diff = -1, c->diff = 0;
      else if (c->diff == -1)
        a->diff = 1, b->diff = 0, c->diff = 0;
      else
        a->diff = 0, b->diff = 0, c->diff = 0;
      a = big_rotate_left(a);
    }
    else {
      if (b->diff == -1)
        b->diff = 0, a->diff = 0;
      else
        b->diff = 1, a->diff = -1;
      a = rotate_left(a);
    }
  } else if (d == 2) {
    Node *b = a->l;
    if (b->diff == -1) {
      Node *c = b->r;
      if (c->diff == -1)
        a->diff = 0, b->diff = 1, c->diff = 0;
      else if (c->diff == 1)
        a->diff = -1, b->diff = 0, c->diff = 0;
      else
        a->diff = 0, b->diff = 0, c->diff = 0;
      a = big_rotate_right(a);
    }
    else {
      if (b->diff == 0)
        b->diff = -1, a->diff = 1;
      else
        b->diff = 0, a->diff = 0;
      a = rotate_right(a);
    }
  }
  return a;
}

Node *AVL::rotate_left(Node *a) {
  Node *b = a->r;
  a->r = b->l;
  b->l = a;
  return b;
}

Node *AVL::rotate_right(Node *a) {
  Node *b = a->l;
  a->l = b->r;
  b->r = a;
  return b;
}

Node *AVL::big_rotate_left(Node *a) {
  a->r = rotate_right(a->r);
  a = rotate_left(a);
  return a;
}

Node *AVL::big_rotate_right(Node *a) {
  a->l = rotate_left(a->l);
  a = rotate_right(a);
  return a;
}

void AVL::print() {
  function<void(Node*, int&)> foo = [&](Node *v, int& i) {
    if (v == nullptr)
      return ;
    v->num = i++;
    foo(v->l, i);
    foo(v->r, i);
  };
  int count = 1;
  foo(root, count);
  print(root);
}

void AVL::print(Node *node) {
  if (node == nullptr)
    return;
  cout << node->key << " " << (node->l == nullptr ? 0 : node->l->num) << " " << (node->r == nullptr ? 0 : node->r->num) << '\n';
  print(node->l);
  print(node->r);
}

int main() {
  freopen("addition.in", "r", stdin);
  freopen("addition.out", "w", stdout);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);



  int t;
  cin >> t;
  vector<vector<int>> vec(t + 1, vector<int>(3));
  for (int i = 1; i <= t; i++)
    for (int j = 0; j < 3; j++)
      cin >> vec[i][j];
  AVL tree(vec);
  int a;
  cin >> a;
  tree.insert(a);
  cout << t + 1 << '\n';
  tree.print();


  return 0;
}