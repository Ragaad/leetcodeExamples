#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& T) {
        stack<int> st;
        int n = (int)T.size();
        vector<int> ans(n, 0);
        for( int i=0; i< T.size(); i++){
            while ( !st.empty() && T[i]>T[st.top()]){
                int j=st.top();
                ans.push_back(i-j);
                st.pop();
                st.push(i);

            }
             
        
             st.push(i);
    }  
       return ans;
    }
        // TODO: Use a monotonic (strictly decreasing by temperature) stack of indices.
        // For each i from 0..n-1:
        //   while stack not empty and T[i] > T[st.top()], pop j and set ans[j] = i - j
        //   push i
        // Remaining indices have ans=0.
        
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    auto out = s.dailyTemperatures({73,74,75,71,69,72,76,73});
    for (int x : out) cout << x << " ";
    cout << "\n";
    return 0;
}
