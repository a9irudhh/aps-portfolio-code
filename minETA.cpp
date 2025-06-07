#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> stages = {
        {15, 20},       // prep times
        {4, 6, 5},      // pickup times
        {12, 14, 10}    // delivery times
    };

    int stages_count = stages.size();
    vector<vector<int>> dp(stages_count, vector<int>(10, INT_MAX));

    for (int i = 0; i < stages[0].size(); ++i)
        dp[0][i] = stages[0][i];

    for (int i = 1; i < stages_count; ++i) {
        for (int j = 0; j < stages[i].size(); ++j) {
            for (int k = 0; k < stages[i - 1].size(); ++k) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + stages[i][j]);
            }
        }
    }

    int min_eta = INT_MAX;
    for (int val : dp[stages_count - 1])
        min_eta = min(min_eta, val);

    cout << "Minimum ETA: " << min_eta << " minutes" << endl;
    return 0;
}
