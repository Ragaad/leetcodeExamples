#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Return all unique triplets [a,b,c] with a+b+c == 0.
    // Order of triplets and elements doesn't matter in the return.
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end()); // sort the array O(n^2)
        int i=0;
        int n=nums.size()-1;
        for ( i=0; i< n; i++){
            if ( i>0 && nums[i]==nums[i+1]) continue;
        int target=-nums[i];
        int l=i+1;
        int r=n-1;
        while( l< r){
            int sum = nums[l]+nums[r];
            if ( target==sum)
            result.push_back({nums[i],nums[l],nums[r]});

            while( nums[l] ==nums[l+1]) ++l;
            while( nums[r]==nums[r-1]) --r; //skip[ redundancy]
            ++l;
            --r;
           if( sum < target)
           l++;
           else 
           r--;
        }

        }

        // TODO: sort + two pointers; skip duplicates
        // Time: O(n^2), Space: O(1) extra (ignoring output)
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<int> v = {-1,0,1,2,-1,-4};
    auto out = s.threeSum(v);           // expect [[-1,-1,2],[-1,0,1]] in any order
    // tiny print
    for (auto &t : out) {
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    }
    cout << "\n";
    return 0;
}
