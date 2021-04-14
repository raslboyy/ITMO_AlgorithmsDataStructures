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

class Node {
 public:
  Node(int value) : value(value), l(nullptr), r(nullptr), p(nullptr){};
  Node* getL() { return l; }
  Node* getR() { return r; }
  void setL(Node* l) {
    this->l = l;
    if (l != nullptr) l->p = this;
  }
  void setR(Node* r) {
    this->r = r;
    if (r != nullptr) r->p = this;
  }
  int getValue() { return value; }
  void setValue(int value) { this->value = value; }
  Node* getP() { return p; }

 private:
  Node* l;
  Node* r;
  Node* p;
  int value;
};

class BinSearchTree {
 public:
  BinSearchTree() : root(nullptr){};
  void insert(int value);
  void erase(int value);
  bool exist(int value);
  int next(int value);
  int prev(int value);

 private:
  Node* find_next(int value);
  Node* find_next(int value, Node* current);
  Node* find_prev(int value);
  Node* find_prev(int value, Node* current);
  Node* min(int value);
  Node* min(int value, Node* current);
  Node* max(int value);
  Node* max(int value, Node* current);
  void insert(int value, Node* current);
  bool exist(int value, Node* current);
  void erase(int value, Node* current);
  int next(int value, Node* current);
  int prev(int value, Node* current);

  Node* root;
};

Node* BinSearchTree::find_next(int value){
  return find_next(value, root);
}

Node* BinSearchTree::find_next(int value, Node* current){
  Node* successor = nullptr;
  while (current != nullptr){
    if (value >= current->getValue())
      current = current->getR();
    else{
      successor = current;
      current = current->getL();
    }
  }
  return successor;
}

Node* BinSearchTree::find_prev(int value){
  return find_prev(value, root);
}

Node* BinSearchTree::find_prev(int value, Node* current){
  value--;
  Node* successor = nullptr;
  while (current != nullptr){
    if (value >= current->getValue()){
      successor = current;
      current = current->getR();
    }
    else
      current = current->getL();
  }
  return successor;
}

Node* BinSearchTree::min(int value){
  return min(value, root);
}

Node* BinSearchTree::min(int value, Node* current){
  while (current->getL() != nullptr)
    current = current->getL();
  return current;
}

Node* BinSearchTree::max(int value){
  return max(value, root);
}

Node* BinSearchTree::max(int value, Node* current){
  while (current->getR() != nullptr)
    current = current->getR();
  return current;
}

void BinSearchTree::insert(int value, Node* current) {
  if (value < current->getValue()) {
    if (current->getL() == nullptr) {
      current->setL(new Node(value));
      return;
    }
    insert(value, current->getL());
  } else {
    if (current->getR() == nullptr) {
      current->setR(new Node(value));
      return;
    }
    insert(value, current->getR());
  }
}

void BinSearchTree::insert(int value) {
  if (exist(value))
    return;
  if (root == nullptr)
    root = new Node(value);
  else
    insert(value, root);
}

bool BinSearchTree::exist(int value, Node* current) {
  while (current != nullptr){
    if (value > current->getValue())
      current = current->getR();
    else if (value < current->getValue())
      current = current->getL();
    else 
      return true;
  }
  return false;
}

bool BinSearchTree::exist(int value) {
  return exist(value, root);
}

void BinSearchTree::erase(int value, Node* current) {
  if (value < current->getValue()) {
    erase(value, current->getL());
    return;
  } else if (value > current->getValue()) {
    erase(value, current->getR());
    return;
  }
  if (current->getL() != nullptr && current->getR() != nullptr) {
    auto v = current->getR();
    while (v->getL() != nullptr) v = v->getL();
    int new_value = v->getValue();
    erase(new_value, v);
    current->setValue(new_value);
  } else if (current == root) {
    root = (current->getL() == nullptr ? current->getR() : current->getL());
  } else if (current->getP()->getL() == current) {
    current->getP()->setL(current->getL() == nullptr ? current->getR()
                                                     : current->getL());
  } else {
    current->getP()->setR(current->getL() == nullptr ? current->getR()
                                                     : current->getL());
  }
}

void BinSearchTree::erase(int value) {
  if (!exist(value)) return;
  if (root == nullptr) return;
  erase(value, root);
}

int BinSearchTree::next(int value, Node* current) {
  current = find_next(value);
  if (current == nullptr)
    return INT_MAX;
  else
    return current->getValue();
}

int BinSearchTree::next(int value) {
  return next(value, root);
}

int BinSearchTree::prev(int value, Node* current) {
  current = find_prev(value);
  if (current == nullptr)
    return INT_MIN;
  else
    return current->getValue();
}

int BinSearchTree::prev(int value) {
  return prev(value, root);
}

int main() {
  freopen("bstsimple.in", "r", stdin);
  freopen("bstsimple.out", "w", stdout);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string command;
  BinSearchTree binTree;
  while (cin >> command) {
    int value, c;
    cin >> value;
    switch (command[0]) {
      case 'i':
        binTree.insert(value);
        break;
      case 'd':
        binTree.erase(value);
        break;
      case 'e':
        cout << (binTree.exist(value) ? "true" : "false") << '\n';
        break;
      case 'n':
        c = binTree.next(value);
        cout << (c == INT_MAX ? "none" : to_string(c)) << '\n';
        break;
      case 'p':
        c = binTree.prev(value);
        cout << (c == INT_MIN ? "none" : to_string(c)) << '\n';
        break;
    }
  }

  return 0;
}