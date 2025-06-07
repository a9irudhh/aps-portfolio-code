#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int hungarian(const vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false);
        int j0 = 0;

        while (true) {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = -1;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
            if (p[j0] == 0) break;
        }

        while (true) {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
            if (j0 == 0) break;
        }
    }

    return -v[0];
}

int main() {
    vector<vector<int>> cost = {
        {9, 11, 14, 11},
        {6, 15, 13, 13},
        {12, 13, 6, 8},
        {11, 9, 10, 12}
    };

    int result = hungarian(cost);
    cout << "Minimum assignment cost: " << result << endl;

    return 0;
}
