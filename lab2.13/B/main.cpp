#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);

    string p, t;
    cin >> p >> t;
    string s = p + "#" + t;

    int n = s.size();
    vector<int> z(n + 1);
    int l = 0;
    for (int i = 1; i < n; i++) {
        z[i] = min(z[i - l], l + z[l] - i);
        z[i] = max(z[i], 0);
        while (s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > l + z[l])
            l = i;
    }

    int count = 0;
    for (int i = 0; i <= n; i++)
        if (z[i] == p.size())
            count++;
    cout << count << '\n';
    for (int i = 0; i <= n; i++)
        if (z[i] == p.size())
            cout << i - p.size() << ' ';

    return 0;
}
