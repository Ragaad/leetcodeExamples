#include "leetcode.hpp"
using namespace std;

class Solution {
public:
long long hours_needed(vector<int>& piles,int h, int k){
         long long hrs=0;
         for ( int p: piles){
            hrs+=(p+k-1)/k; // memorized formula
            if ( hrs > (long long ) h) return hrs;
         }
         return hrs;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); // k ∈ [1, maxPile]
        
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long k=hours_needed(piles,h,mid);
            if ( k <= h)
            r=mid;
            else
            l=mid+1;
            
        }
        return l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> piles = {3,6,7,11};
    int h = 8;
    Solution s;
    cout << s.minEatingSpeed(piles, h) << "\n"; // expect 4
    return 0;
}
