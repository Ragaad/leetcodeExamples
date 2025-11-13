#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Remove all occurrences of val in-place; return new length k.
    // Elements beyond k are don't-care. Order may change.
    int removeElement(vector<int>& nums, int val) {
        if ( nums.empty()) return 0;
        // TODO: two-pointer write index; skip == val
        int index=0;
        for ( int i=0; i<nums.size(); i++){
            if ( nums[i]!=val){
                nums[index]=nums[i];
                index++;
            }
        }
        return index; // replace
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<int> a{3,2,2,3};
    int k = s.removeElement(a, 3); // expect 2; first 2 elements are 2,2 (any order)
    cout << k << "\n";
    return 0;
}
