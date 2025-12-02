
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i=0; i<(int)nums.size(); ++i) {
            int need = target - nums[i];
            if (auto it = m.find(need); it != m.end()) return {it->second, i};
            m[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    auto ans = s.twoSum({2,7,11,15}, 9);
    cout << ans[0] << " " << ans[1] << "\n"; // 0 1
    return 0;
}
