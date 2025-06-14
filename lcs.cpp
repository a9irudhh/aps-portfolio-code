#include <bits/stdc++.h>
using namespace std;

int LCS(const string& A, const string& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}

int main() {
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << LCS(s1, s2) << endl;
    return 0;
}
