#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int minP = INT_MAX, best = 0;
        for (int p : prices) {
            minP = min(minP, p);
            best = max(best, p - minP);
        }
        return best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    cout << s.maxProfit({7,1,5,3,6,4}) << "\n"; // 5
    return 0;
}
