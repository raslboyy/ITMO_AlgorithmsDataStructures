#include <bits/stdc++.h>
#include <iostream>

#define mp make_pair
#define pb put_back
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

class Quack {
 public:
  Quack() { _register.assign(27, 0); }
  void add_command(string str);
  void start_program();

 private:
  int get();
  void put(int value);
  void plus();
  void minus();
  void multiplication();
  void div();
  void mod();
  void to_register(char ch);
  void from_register(char ch);
  void to_console();
  void register_to_console(char ch);
  void char_to_console();
  void char_from_register_to_console(char ch);
  int find_function(string str);

  queue<int> _q;
  vector<string> _commands;
  vector<pair<string, int>> _function;
  veci _register;
  const int modulo = 65536;
};

int Quack::get() {
  int a = _q.front();
  _q.pop();
  return a;
}

void Quack::put(int value) { _q.push(value); }

int Quack::find_function(string str) {
  auto p = mp(str, 0);
  int index = lower_bound(all(_function), p) - _function.begin();
  return index;
}

void Quack::add_command(string str) {
  _commands.emplace_back(str);
  if (str[0] == ':')
    _function.emplace_back(str.substr(1, sz(str) - 1), sz(_commands) - 1);
}

void Quack::start_program() {
  sort(all(_function));
  for (int i = 0; i < sz(_commands); i++) {
    string current_command = _commands[i];
    int index;
    switch (current_command[0]) {
      case '+':
        plus();
        break;
      case '-':
        minus();
        break;
      case '*':
        multiplication();
        break;
      case '/':
        div();
        break;
      case '%':
        mod();
        break;
      case '>':
        to_register(current_command[1]);
        break;
      case '<':
        from_register(current_command[1]);
        break;
      case 'P':
        if (sz(current_command) == 1)
          to_console();
        else
          register_to_console(current_command[1]);
        break;
      case 'C':
        if (sz(current_command) == 1)
          char_to_console();
        else
          char_from_register_to_console(current_command[1]);
        break;
      case ':':
        break;
      case 'J':
        index =
            find_function(current_command.substr(1));
        i = _function[index].y;
        break;
      case 'Z':
        if (_register[current_command[1] - 'a'] != 0) break;
        index =
            find_function(current_command.substr(2));
        i = _function[index].y;
        break;
      case 'E':
        if (_register[current_command[1] - 'a'] !=
            _register[current_command[2] - 'a'])
          break;
        index =
            find_function(current_command.substr(3));
        i = _function[index].y;
        break;
      case 'G':
        if (_register[current_command[1] - 'a'] <=
            _register[current_command[2] - 'a'])
          break;
        index =
            find_function(current_command.substr(3));
        i = _function[index].y;
        break;
      case 'Q':
        exit(0);
        break;
      default:
        if (sz(current_command) > 0 && current_command[0] >= '0' && current_command[0] <= '9')
          put(stoi(current_command));
        break;
    }
  }
}

void Quack::plus() {
  int a = get();
  int b = get();
  put((a + b) % modulo);
}

void Quack::minus() {
  int a = get();
  int b = get();
  put((a - b + 2*modulo) % modulo);
}

void Quack::multiplication() {
  int a = get();
  int b = get();
  put((a * 1ll * b) % modulo);
}

void Quack::div() {
  int a = get();
  int b = get();
  if (b == 0)
    put(0);
  else
    put(a / b);
}

void Quack::mod() {
  int a = get();
  int b = get();
  if (b == 0)
    put(0);
  else
    put(a % b);
}

void Quack::to_register(char ch) { _register[ch - 'a'] = get(); }

void Quack::from_register(char ch) { put(_register[ch - 'a']); }

void Quack::to_console() {
  int a = get();
  cout << a << endl;
}

void Quack::register_to_console(char ch) {
  cout << _register[ch - 'a'] << endl;
}

void Quack::char_to_console() { cout << char(get()); }

void Quack::char_from_register_to_console(char ch) {
  cout << char(_register[ch - 'a']);
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //freopen("quack.in", "r", stdin);
  //freopen("quack.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Quack my_program;
  string str;
  // getline(cin, str);
  while (cin >> str) my_program.add_command(str);

  my_program.start_program();

  return 0;
}