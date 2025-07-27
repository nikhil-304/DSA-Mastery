class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // use long long to handle INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {    // if exponent is odd
                result *= x;
            }
            x = x * x;      // square the base
            N = N/2;        // halve the exponent
        }

        return result;
    }
};

//Problem Link: https://leetcode.com/problems/powx-n/

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/

/*
Example for `x = 2` and `n = 9`:

1. Start with `x = 2`, `n = 9`, and `result = 1`
2. Since `n` is odd (9), multiply the result by `x`: `result = 1 * 2 = 2`
3. Now, square `x` and halve `n`: `x = 2^2 = 4`, `n = 9 / 2 = 4`
4. Since `n` is even (4), just square `x`: `x = 4^2 = 16`, `n = 4 / 2 = 2`
5. Since `n` is even (2), just square `x`: `x = 16^2 = 256`, `n = 2 / 2 = 1`
6. Since `n` is odd (1), multiply the result by `x`: `result = 2 * 256 = 512`
7. The final result is `512`.

So, instead of multiplying 2 by itself 9 times, we efficiently reduce the problem to squaring and halving, which reduces the number of operations to `O(log n)`.
*/
