#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Merge all overlapping intervals and return non-overlapping intervals.
    // intervals[i] = {start, end}, with start <= end
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // TODO:
        // 1) sort by start
        std::sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
             if (a[0] != b[0]) return a[0] < b[0];
             return a[1] < b[1];);
        // 2) sweep once, merging into an output vector
        vector<vector<int>> merged;
        for (const auto& interval: intervals){
            if (merged.empty() || merged.back()[1] < interval[0])
             merged.push_back(interval);
            else{
                merged.back()[1]=max(merged.back()[1], interval[1]);
            } 
        }
        // Time: O(n log n), Space: O(1) extra (excluding output)
        return merged;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<vector<int>> a{{1,3},{2,6},{8,10},{15,18}};
    auto out = s.merge(a);  // expect {{1,6},{8,10},{15,18}}
    for (auto &iv : out) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << "\n";
    return 0;
}
