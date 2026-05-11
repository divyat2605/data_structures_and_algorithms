# Splitting Array Digits — Two Approaches

---

## Approach 1: Simulation

### Intuition

The problem requires splitting each number in the array into its individual digits and then reassembling those digits in order to form a new array.

When splitting a number `x` digit by digit:

1. Taking `x mod 10` gives the digit in the units place, which we store in a temporary array.
2. Dividing `x` by `10` removes the digit in the units place.

We repeat this process until `x` becomes `0`, which gives us the digits of `x` in **reverse order**. Since all values of `x` in the input are positive integers, we do not need to handle the case where `x` starts as `0`.

After that, we traverse the temporary array in reverse order and append each digit to the result array. Once done, we clear the temporary array and continue with the next number. Finally, we return the result array.

### Complexity Analysis

Let `n` be the length of `nums`, and let `M` be the maximum value in `nums`.

| | Complexity |
|---|---|
| **Time** | O(n log M) |
| **Space** | O(log M) |

> The output array is not included in the space complexity.

---

## Approach 2: Reverse Traversal

### Intuition

In Approach 1, we use a temporary array to store the digits and then append them in reverse order to the result array. Instead, we can traverse `nums` in **reverse order** and directly append each digit of `x` to the result array as we extract it, without using a temporary array. Finally, we reverse the result array to obtain the correct order.

### Complexity Analysis

Let `n` be the length of `nums`, and let `M` be the maximum value in `nums`.

| | Complexity |
|---|---|
| **Time** | O(n log M) |
| **Space** | O(1) |

> The output array is not included in the space complexity.