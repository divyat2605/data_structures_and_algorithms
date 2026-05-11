// LeetCode 58 - Length of Last Word
// Approach: Reverse traversal — O(n) time, O(1) space
// Beats 97.43% | Author: Firdavs | Apr 01, 2024

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            }
            else if (counting) {
                break;
            }
        }

        return length;
    }
};