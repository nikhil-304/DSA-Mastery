#include <iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to perform fast exponentiation
    long long power(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;

        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp = exp/2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2; // ceil(n/2)
        long long oddPos = n / 2;        // floor(n/2)

        long long evenWays = power(5, evenPos);
        long long oddWays = power(4, oddPos);

        return (evenWays * oddWays) % MOD;
    }
};

//Problem Link: https://leetcode.com/problems/count-good-numbers/

/*
Time Complexity: O(log(n))
Space Complexity: O(1)
*/
