// 2784. Check if Array is Good
// Difficulty: Easy | Topic: Sorting, Array
// Status: Accepted
// https://leetcode.com/problems/check-if-array-is-good/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.back(); // max element = only valid candidate for base[n]

        // base[n] has exactly n+1 elements
        if ((int)nums.size() != n + 1) return false;

        // nums[0..n-2] must be 1, 2, ..., n-1
        for (int i = 0; i <= n - 2; i++) {
            if (nums[i] != i + 1) return false;
        }

        // last two elements must both be n
        if (nums[n - 1] != n || nums[n] != n) return false;

        return true;
    }
};