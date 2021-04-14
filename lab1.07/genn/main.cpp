#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
  freopen("input.txt", "w", stdout);

  int size = 2000;
  cin >> size;
  vector<string> a(size, "A 0");
  for (int i = 0; i < size / 2; i++) {
    a[i] = "A " + to_string(i);
  }
  for (int i = size/2; i < size; i++) {
    a[i] = "D " + to_string(i - (size/2));
  }
  srand(time(NULL));
  random_shuffle(a.begin(), a.begin() + size/2);
  random_shuffle(a.begin() + size/2, a.end());
  cout << size << endl;
  for (string i : a)
    cout << i << endl;


  return 0;
}