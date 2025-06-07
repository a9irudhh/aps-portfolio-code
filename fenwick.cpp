#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= n) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    int prefixSum(int index) {
        int res = 0;
        while (index > 0) {
            res += bit[index];
            index -= index & -index;
        }
        return res;
    }

    int rangeSum(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

int main() {
    FenwickTree tree(10);
    tree.update(1, 5);
    tree.update(2, 3);
    tree.update(5, 7);

    cout << tree.prefixSum(5) << endl;
    cout << tree.rangeSum(2, 5) << endl;
    cout << tree.prefixSum(1) << endl;

    return 0;
}
