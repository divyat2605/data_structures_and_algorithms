// 205. Isomorphic Strings
// Difficulty: Easy | Topic: Hash Map
// Runtime: 0 ms | Status: Accepted
// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        // Bidirectional mapping to enforce one-to-one character correspondence
        unordered_map<char, char> mp1; // s -> t
        unordered_map<char, char> mp2; // t -> s

        for (int i = 0; i < (int)s.length(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check s -> t mapping consistency
            if (mp1.count(c1) && mp1[c1] != c2) return false;

            // Check t -> s mapping consistency
            if (mp2.count(c2) && mp2[c2] != c1) return false;

            mp1[c1] = c2;
            mp2[c2] = c1;
        }

        return true;
    }
};