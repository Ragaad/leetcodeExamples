#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Return the max water area between two lines at indices i<j:
    // area = (j - i) * min(height[i], height[j])
    int maxArea(const vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        while ( left< right){
            if ( height[left] >=height[right])
            {
                int h= min( height[left],height[right]);
                int w=abs(right-left);
                area=max(area, w*h);
            }
            if ( height[left] < height[right])
            left++;
            else 
            right--;
        }
        // TODO: two pointers from both ends; move the smaller height inward.
        // Time: O(n), Space: O(1)
        return area; // replace
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    cout << s.maxArea(vector<int>{1,8,6,2,5,4,8,3,7}) << "\n"; // expect 49
    return 0;
}
