#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    string p, t;
    cin >> p >> t;
    vector<int> r;
    for (int i = 0; i <= (int)t.size() - (int)p.size(); i++) {
        bool f = true;
        for (int j = 0; j < p.size() && i + j < t.size(); j++)
            if (t[i + j] != p[j]) {
                f = false;
                break;
            }
        if (f)
            r.emplace_back(i);
    }

    cout << r.size() << '\n';
    for (int i : r)
        cout << i + 1 << ' ';

    return 0;
}
