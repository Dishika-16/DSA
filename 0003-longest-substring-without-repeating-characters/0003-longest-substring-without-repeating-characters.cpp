#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> seen;  // to store characters in current window
        int left = 0;              // left pointer
        int maxLength = 0;         // answer

        for(int right = 0; right < s.length(); right++) {

            // If character already exists, move left pointer
            while(seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            // Add current character
            seen.insert(s[right]);

            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};