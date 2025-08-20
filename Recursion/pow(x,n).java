/*

Link: https://leetcode.com/problems/powx-n/description/

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

*/


### ✅ Key Concepts:

We use **Exponentiation by Squaring** — a divide-and-conquer recursive technique to reduce time complexity from **O(n)** to **O(log n)**.

---

### ⚙️ Recursive Rules:

| Case     | Formula                | Explanation                                   |
| -------- | ---------------------- | --------------------------------------------- |
| `n == 0` | `x⁰ = 1`               | Base case                                     |
| `n < 0`  | `x⁻ⁿ = 1 / xⁿ`         | Convert negative to positive, take reciprocal |
| `n` even | `xⁿ = (x^(n/2))²`      | Halve the exponent                            |
| `n` odd  | `xⁿ = x * (x^(n//2))²` | Halve exponent + multiply one extra `x`       |

---

### 💡 Why Even and Odd Are Handled Differently:

#### ✅ Even Power:

x = 3, n = 4 → 3^4
half = pow(3, 2) = 9
3^4 = half * half = 9 * 9 = 81

#### ✅ Odd Power:

x^5 = x * x^4
     = x * (x^2)^2

     or

x = 2, n = 5 → 2^5
half = pow(2, 2) = 4
2^5 = x * half * half = 2 * 4 * 4 = 32



class Solution {
    public double myPow(double x, int n) {
        // Convert n to long to handle Integer.MIN_VALUE safely
        long N = n;

        // Handle negative exponent by taking reciprocal
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        // Recursive helper function
        return power(x, N);
    }

    private double power(double x, long n) {
        // Base case
        if (n == 0) return 1;

        // Recursively calculate half power
        double half = power(x, n / 2);

        // Even power: x^n = half * half
        if (n % 2 == 0) {
            return half * half;
        } 
        // Odd power: x^n = x * half * half
        else {
            return x * half * half;
        }
    }
}

---

### 📊 Time & Space Complexity:

* **Time:** O(log n) — we halve `n` in each recursive call.
* **Space:** O(log n) — due to recursive stack.



