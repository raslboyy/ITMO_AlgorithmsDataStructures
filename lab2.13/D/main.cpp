#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {

    int a;
    cin >> a;
    string p;
    cin >> p;

    int n = p.size();
    vector<int> pref(n + 1);
    pref[0] = -1;
    for (int i = 1; i <= n; i++) {
        int k = pref[i - 1];
        while (k >= 0) {
            if (p[i - 1] == p[k])
                break;
            k = pref[k];
        }
        pref[i] = k + 1;
    }

    vector<vector<int>> machine(n + 1, vector<int>(a));
    for (int i = 0; i < n; i++)
        machine[i][p[i] - 'a'] = i + 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < a; j++)
            if (i == n || j != p[i] - 'a')
                machine[i][j] = machine[pref[i]][j];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < a; j++)
            cout << machine[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
