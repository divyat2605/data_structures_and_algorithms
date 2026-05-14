# Length of Last Word — Easy | ✅ 97.43% Beats

**Tags:** String · C++ 

---

## Intuition

To solve this problem, we need to find the last word in the string and return its length. We can achieve this by traversing the string from the end, skipping trailing spaces, then counting characters until we hit another space.

---

## Approach

1. Traverse the string from right to left.
2. Skip any trailing whitespace before a word begins.
3. Once a non-space character is found, start counting (`counting = true`) and increment `length`.
4. If we encounter a space **after** we've started counting, we've passed the last word — `break`.
5. Return `length`.

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(n) — single pass from the end |
| **Space** | O(1) — no extra storage used |

---

## Code

```cpp
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
```
