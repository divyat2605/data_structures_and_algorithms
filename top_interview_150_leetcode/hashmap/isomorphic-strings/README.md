# 205. Isomorphic Strings

**Difficulty:** Easy  
**Topic:** Hash Map  
**Study Plan:** [Top Interview 150](https://leetcode.com/studyplan/top-interview-150/)  
**Problem Link:** https://leetcode.com/problems/isomorphic-strings/

---

## Problem Statement

Given two strings `s` and `t`, determine if they are isomorphic.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.  
All occurrences of a character must be replaced with another character while preserving the order of characters. **No two characters may map to the same character**, but a character may map to itself.

---

## Examples

**Example 1:**
```
Input:  s = "egg", t = "add"
Output: true
Explanation: 'e' → 'a', 'g' → 'd'
```

**Example 2:**
```
Input:  s = "f11", t = "b23"
Output: false
Explanation: '1' would need to map to both '2' and '3' — invalid.
```

**Example 3:**
```
Input:  s = "paper", t = "title"
Output: true
```

---

## Approach — Bidirectional Hash Map

The key insight is that isomorphism requires a **one-to-one mapping** in both directions:
- Every character in `s` maps to exactly one character in `t` (`s → t`)
- Every character in `t` maps to exactly one character in `s` (`t → s`)

Maintaining only one direction is insufficient. For example, `s = "ab"`, `t = "aa"` would pass a one-way check but is not isomorphic.

**Algorithm:**
1. Maintain two hash maps: `mp1` for `s→t` and `mp2` for `t→s`.
2. For each index `i`, check if the existing mapping (if any) is consistent.
3. If any conflict is found, return `false`. Otherwise, record the mapping and continue.

---

## Complexity

| | Complexity |
|---|---|
| **Time** | O(n) — single pass through both strings |
| **Space** | O(1) — at most 256 ASCII entries per map |

---

## Solution

See [`solution.cpp`](./solution.cpp)

---

## Result

| Status | Runtime | Language |
|--------|---------|----------|
| ✅ Accepted | 0 ms | C++ |