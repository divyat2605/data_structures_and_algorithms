// 1674. Minimum Moves to Make Array Complementary
// Difficulty: Medium | Topic: Array, Hash Map, Binary Search
// Status: Accepted
// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        unordered_map<int, int> sum_count; // existing pair sums
        vector<int> min_arr, max_arr;      // per-pair (min, max)
        min_arr.reserve(n / 2);
        max_arr.reserve(n / 2);

        for (int i = 0; i < n / 2; ++i) {
            int a = min(nums[i], nums[n - i - 1]);
            int b = max(nums[i], nums[n - i - 1]);
            sum_count[a + b]++;
            min_arr.push_back(a);
            max_arr.push_back(b);
        }

        sort(min_arr.begin(), min_arr.end());
        sort(max_arr.begin(), max_arr.end());

        int min_ops = n; // upper bound: replace every element

        // Try every candidate target sum c in [2, 2*limit]
        for (int c = 2; c <= 2 * limit; ++c) {
            // Pairs where min >= c: sum already >= c+1, need 2 moves
            int add_left = n / 2 - (int)(lower_bound(min_arr.begin(), min_arr.end(), c) - min_arr.begin());

            // Pairs where max < c - limit: can't reach c even with max swap, need 2 moves
            int add_right = (int)(lower_bound(max_arr.begin(), max_arr.end(), c - limit) - max_arr.begin());

            // Base: 1 move per pair; subtract saved moves for pairs already at c
            int current_ops = n / 2 + add_left + add_right - sum_count[c];

            min_ops = min(min_ops, current_ops);
        }

        return min_ops;
    }
};