# 1674. Minimum Moves to Make Array Complementary

**Difficulty:** Medium  
**Topic:** Array, Hash Map, Prefix Sum  
**Problem Link:** https://leetcode.com/problems/minimum-moves-to-make-array-complementary/

---

## Problem Statement

Given an integer array `nums` of even length `n` and an integer `limit`, in one move you can replace any element with any value in `[1, limit]`.

Return the **minimum number of moves** to make `nums` complementary — i.e., every pair `nums[i] + nums[n-1-i]` equals the same target sum `T`.

---

## Examples

**Example 1:**
```
Input:  nums = [1,2,4,3], limit = 4
Output: 1
Explanation: Change 4 → 2; all pairs sum to 4.
```

**Example 2:**
```
Input:  nums = [1,2,2,1], limit = 2
Output: 2
```

**Example 3:**
```
Input:  nums = [1,2,1,2], limit = 2
Output: 0  (already complementary)
```

---

## Approach — Binary Search on Sorted Pairs

For a target sum `c` (ranging from `2` to `2*limit`), each pair `(a, b)` where `a = min`, `b = max` requires:

| Condition | Moves needed |
|---|---|
| `a + b == c` | 0 |
| `a + 1 <= c <= b + limit` | 1 (change one element) |
| otherwise | 2 (change both elements) |

**Key insight:** Start with a base cost of `n/2` (1 move per pair as default), then adjust using binary search:

- `add_left`: pairs where even 1 move won't achieve `c` from the right side — need 2 moves. Count pairs where `a >= c` (can't reach `c` even setting the other to 1... actually `min >= c` means sum already ≥ c+1).
- `add_right`: pairs where `b < c - limit` — can't reach `c` from the left side either.
- Subtract `sum_count[c]`: pairs already summing to `c` (no move needed → save 1).

**Formula per target `c`:**
```
ops = (n/2) + (pairs where min >= c) + (pairs where max < c - limit) - (pairs already at sum c)
```

**Pre-sort** `min_arr` and `max_arr` to enable O(log n) binary search per candidate.

---

## Complexity

| | Complexity |
|---|---|
| **Time** | O(n log n + limit log n) |
| **Space** | O(n) |

---

## Solution

See [`solution.cpp`](./solution.cpp)

---

## Result

| Status | Runtime | Language |
|--------|---------|----------|
| ✅ Accepted | — ms | C++ |