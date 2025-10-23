
#include "leetcode.hpp"
using namespace std;

// Replace with the actual solution for this problem
class Solution {
public:
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open_par=0,close_par=0;
         backtrack(res, "", 0,0,n);
         return res;
        
    }
    void backtrack(vector<string>& res, string current_string, int opens, int closes,int n){
        if ( opens==n && closes==n)
        {
            res.push_back(current_string);
        return;
        }
        if ( opens<n){
        backtrack(res, current_string + '(', opens+1, closes, n);
        }
        if (  closes <opens){
        backtrack(res, current_string + ')', opens, closes+1, n);
        }
    
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<string> res=s.generateParenthesis(3);
    for ( auto s:res)
    cout << s <<",";
    cout<<endl;
    return 0;
}
