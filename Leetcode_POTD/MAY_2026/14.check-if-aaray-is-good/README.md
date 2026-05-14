# 2784. Check if Array is Good

**Difficulty:** Easy  
**Topic:** Sorting, Array  
**Problem Link:** https://leetcode.com/problems/check-if-array-is-good/

---

## Problem Statement

An array is **good** if it is a permutation of `base[n]`, where:

```
base[n] = [1, 2, ..., n-1, n, n]
```

i.e., contains integers `1` to `n-1` exactly once, plus `n` exactly **twice**.

Return `true` if `nums` is a good array, otherwise `false`.

---

## Examples

**Example 1:**
```
Input:  nums = [2, 1, 3]
Output: false
Explanation: max = 3, but size is 3 (need 4 for base[3])
```

**Example 2:**
```
Input:  nums = [1, 3, 3, 2]
Output: true
Explanation: Permutation of base[3] = [1, 2, 3, 3]
```

**Example 3:**
```
Input:  nums = [1, 1]
Output: true
Explanation: Permutation of base[1] = [1, 1]
```

**Example 4:**
```
Input:  nums = [3, 4, 4, 1, 2, 1]
Output: false
Explanation: max = 4, but size is 6 (need 5 for base[4])
```

---

## Approach — Sort + Validate

After sorting, a valid `base[n]` array looks exactly like `[1, 2, 3, ..., n-1, n, n]`.

**Algorithm:**
1. Sort `nums`.
2. Let `n = nums.back()` (the maximum element — the only valid candidate).
3. Check `nums.size() == n + 1` (length must be exactly `n+1`).
4. Verify `nums[i] == i + 1` for indices `0` to `n-2`.
5. Verify the last two elements are both `n`.

---

## Complexity

| | Complexity |
|---|---|
| **Time** | O(n log n) — dominated by sort |
| **Space** | O(1) — in-place sort |

---

## Solution

See [`solution.cpp`](./solution.cpp)

---

## Result

| Status | Runtime | Language |
|--------|---------|----------|
| ✅ Accepted | — ms | C++ |