#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &g, vector<vector<int>> &dp, int v) {
    if (g[v].empty())
        return ;
    for (int to : g[v]) {
        dfs(g, dp, to);
        dp[v][0] += max(dp[to][0], dp[to][1]);
        dp[v][1] += dp[to][0];
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    int root;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0)
            root = i;
        else
            g[--a].emplace_back(i);
    }

    vector<vector<int>> dp(n, vector<int>{0, 1});
    dfs(g, dp, root);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
