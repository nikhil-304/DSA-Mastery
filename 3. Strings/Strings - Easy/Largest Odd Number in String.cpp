class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

//Problem Link: https://leetcode.com/problems/largest-odd-number-in-string/description/

/*
Time complexity: O(n)
Space complexity: O(1)
*/

/*
Approach:

1. Check from the end of the string: The largest odd number will always be the largest possible odd number from the string, and if we consider the string from the end, we can stop as soon as we find an odd number.

2. Odd number condition: A number is odd if the last digit of the number is odd, i.e., if it's one of the characters '1', '3', '5', '7', or '9'.

3. Iterate backwards: Start iterating from the last character and move backward, checking if the character is odd. Once an odd digit is found, we can consider all the digits before it as part of the largest odd number.

4. Stop early: As soon as we find the first odd digit, the substring from the start of the string to this digit is the largest odd number.
*/
