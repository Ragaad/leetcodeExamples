#include <iostream>
#include <math.h>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.empty()) {
                return "";
            }
    
            int n = s.size();
            int start = 0;
            int maxLength = 1; 
    
            // Function to check for palindrome centered at i
            auto expandAroundCenter = [&](int left, int right) {
                while (left >= 0 && right < n && s[left] == s[right]) {
                    left--;
                    right++;
                }
                return right - left - 1; // Length of the palindrome
            };
    
            for (int i = 0; i < n; ++i) {
                // Find the longest palindrome centered at i
                int len1 = expandAroundCenter(i, i); // For odd length palindromes
                int len2 = expandAroundCenter(i, i + 1); // For even length palindromes
    
                int currentMax = std::max(len1, len2); 
                if (currentMax > maxLength) {
                    maxLength = currentMax;
                    start = i - (currentMax - 1) / 2; // Adjust start for correct substring
                }
            }
    
            return s.substr(start, maxLength);
        }
    };

    int main(int argc, char* args[]){
        return 0;
    }