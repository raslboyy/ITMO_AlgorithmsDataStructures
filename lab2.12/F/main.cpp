#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<pair<int, vector<int>>> &g, vector<vector<int>> &dp, int v) {
    if (g[v].second.empty())
        return ;
    for (int to : g[v].second) {
        dfs(g, dp, to);
        dp[v][0] += max(dp[to][0], dp[to][1]);
        dp[v][1] += dp[to][0];
    }
}

int main() {

    freopen("selectw.in", "r", stdin);
    freopen("selectw.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, vector<int>>> g(n);
    int root;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[i].first = b;
        if (a == 0)
            root = i;
        else
            g[--a].second.emplace_back(i);
    }

    vector<vector<int>> dp(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        dp[i][1] = g[i].first;
    dfs(g, dp, root);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
