// 392. Is Subsequence
// Difficulty: Easy | Topic: Two Pointers
// Runtime: 0 ms | Status: Accepted
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < (int)s.length() && j < (int)t.length()) {
            if (s[i] == t[j]) i++;
            j++;
        }

        return i == (int)s.length();
    }
};

// Follow-up: O(m log n) per query after O(n) preprocessing
// Preprocess t: map each char -> sorted list of indices
// For each char in s, binary search (lower_bound) for next valid index in t