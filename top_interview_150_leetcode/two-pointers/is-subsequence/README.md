# 392. Is Subsequence

**Difficulty:** Easy  
**Topic:** Two Pointers  
**Study Plan:** [Top Interview 150](https://leetcode.com/studyplan/top-interview-150/)  
**Problem Link:** https://leetcode.com/problems/is-subsequence/

---

## Problem Statement

Given two strings `s` and `t`, return `true` if `s` is a subsequence of `t`, or `false` otherwise.

A subsequence is formed by deleting some (or none) characters from the original string without disturbing the relative order of the remaining characters.

---

## Examples

**Example 1:**
```
Input:  s = "abc", t = "ahbgdc"
Output: true
```

**Example 2:**
```
Input:  s = "axc", t = "ahbgdc"
Output: false
```

---

## Approach — Two Pointers

Use two pointers `i` (over `s`) and `j` (over `t`). Advance `i` only when characters match; always advance `j`. If `i` reaches the end of `s`, all characters were found in order — return `true`.

**Algorithm:**
1. Initialize `i = 0`, `j = 0`.
2. While both pointers are in bounds:
   - If `s[i] == t[j]`, increment `i`.
   - Always increment `j`.
3. Return `i == s.length()`.

---

## Follow-up: Multiple Queries (k ≥ 10⁹ strings)

Re-running the O(n) scan per query becomes expensive at scale. Instead:

**Preprocess `t`** — build a map from each character to its sorted list of indices in `t`. For each character in `s`, binary search for the next valid index in `t` (using `lower_bound`). This reduces each query to **O(m log n)** after **O(n)** preprocessing — amortized much faster for large `k`.

---

## Complexity

| | Complexity |
|---|---|
| **Time** | O(n) — single pass through `t` |
| **Space** | O(1) — no extra data structures |

---

## Solution

See [`solution.cpp`](./solution.cpp)

---

## Result

| Status | Runtime | Language |
|--------|---------|----------|
| ✅ Accepted | 0 ms | C++ |