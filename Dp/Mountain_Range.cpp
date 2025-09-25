#include <bits/stdc++.h>
#define int long long
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &dp) {
    if (dp[i] != -1) return dp[i];
    int ans = 1; 
    for (int nxt : adj[i]) {
        ans = max(ans, 1 + dfs(nxt, adj, dp));
    }
    return dp[i] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> leftSmaller(n, -1), rightSmaller(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (!st.empty()) leftSmaller[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (!st.empty()) rightSmaller[i] = st.top();
        st.push(i);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (leftSmaller[i] != -1) adj[i].push_back(leftSmaller[i]);
        if (rightSmaller[i] != -1) adj[i].push_back(rightSmaller[i]);
    }

    vector<int> dp(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i, adj, dp));
    }

    cout << ans << "\n";
}
