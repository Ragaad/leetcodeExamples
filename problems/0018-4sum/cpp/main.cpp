#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Return all unique triplets [a,b,c] with a+b+c == 0.
    // Order of triplets and elements doesn't matter in the return.
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        if ( nums.size()<4)
        return {};
        int n=nums.size();
        for ( int i=0; i< nums.size(); i++){
            if ( nums[i]+nums[i+1]+nums[i+1]+nums[i+3]>target)
            break; // there is no soultion
            if ( nums[i]+nums[n-1]+nums[n-2]+nums[n-3] <target)
            continue;
            while( i< nums.size() && nums[i]==nums[i+1]) continue;
            
            for ( int j=i+1 ; j< nums.size(); j++)
            {
                // prunining 
                while ( nums[j]==nums[j+1]) continue;
                if ( nums[i]+nums[j]+nums[j+1]+nums[j+2] >target ) break;
                if ( nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;
                int l=j+1;
                int r=n-1;
                while( l<r){
                    int sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if ( sum==target)
                    result.push_back({nums[i],nums[j],nums[l],nums[r]});
                    if (sum <target)
                    l++;
                    else r--;

                }
            
        }
        
        

        return result;
    }
}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    int target=4;
    vector<int> v = {-1,0,1,2,-1,-4};
    auto out = s.fourSum(v, target);           // expect [[-1,-1,2],[-1,0,1]] in any order
    // tiny print
    for (auto &t : out) {
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    }
    cout << "\n";
    return 0;
}
