#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n + 1);
    p[0] = -1;
    for (int i = 1; i <= n; i++) {
        int k = p[i - 1];
        while (k >= 0) {
            if (s[k] == s[i - 1])
                break;
            k = p[k];
        }
        p[i] = k + 1;
    }

    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';

    return 0;
}
