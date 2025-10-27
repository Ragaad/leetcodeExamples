#include "leetcode.hpp"
using namespace std;

// Return true if s2 contains a permutation of s1 (both are lowercase letters).
class Solution {
public:
    bool checkInclusion(const string& s1, const string& s2) {

        int m=s1.size();
        int n=s2.size();
        if (m>n) return false;
        int a[26]={0}, b[26]={0}; // to keep the matches 
        for ( char c: s1) a[c-'a']=1;
        for( int i=0; i<m; i++) b[s2[i]-1]=1;
        int matches=0;
        for ( int k=0; k<26; k++)
            if(a[k]==b[k])
                matches++;
        for( int i=0; i<=n-m; i++){
            if ( matches==26) return true;
            if ( i==n-m) break;
            int out=s2[i]-'a', in=s1[i+m]-'a'; //widows size i, i+m
            if ( a[in]==b[in]) matches--;
            b[in]++;
            if (a[in]==b[in]) matches++;
            if ( a[out]==b[out]) matches--;
            b[out]--;
            if(a[out]==b[out]) matches++;

        }  
        return matches==26;      
        // TODO: fixed-size sliding window of length |s1|
        // Hint: keep two freq arrays of size 26 and a "matches" counter.
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    cout << boolalpha << sol.checkInclusion("ab", "eidbaooo") << "\n"; // expect true
    return 0;
}
