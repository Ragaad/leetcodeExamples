#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // In-place remove duplicates from sorted nums.
    // Return new length k; the first k elements must be the deduplicated array.
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        // TODO: two-pointer write index
        int index=1;
        for ( int i=1; i< nums.size(); i++){
            if ( nums[i]!=nums[i-1]){
                nums[index]=nums[i];
                index ++;
            }
        }
        return index; // replace
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<int> a{1,1,2};
    int k = s.removeDuplicates(a);           // expect k=2, a[0..1]={1,2}
    cout << k << "\n";
    return 0;
}
