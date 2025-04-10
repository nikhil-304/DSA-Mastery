class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;

        int i = 0;
        //Remove whitespaces
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        //After removing whitespaces reinitialise the string
        s = s.substr(i);

        int sign = +1;
        long ans = 0;

        //Checking the sign
        if(s[0] == '-') sign = -1;

        int max = INT_MAX, min = INT_MIN;

        //Index:  0-1-2   -----  0-1
        //String: - 4 2   -----  4 2
        //if "+" || "-" sign; start from index 1 or else from 0
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while(i < s.length()){
           if(s[i] == ' ' || !isdigit(s[i])) break; 

            ans = ans * 10 + (s[i] - '0');
            if(sign == -1 && -1*ans < min) return min;
            if(sign == 1 && 1*ans > max) return max;

            i++;
        }
        return (int)(sign*ans);
    }
    
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/string-to-integer-atoi/description/
Code360: https://www.naukri.com/code360/problems/atoi_981270
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Initial Input:
    s = "  -42"
Step-by-Step Execution:
    Whitespace removal:
        The initial string has leading spaces, so the first loop removes them.
        After this, the string s becomes "  -42", and i becomes 2.
    Checking for Sign:
        Now, i = 0 and s[0] == '-', so the sign is set to -1.
    Processing Digits:
        Now, we move to process the number starting from index i = 1. The first character is '4', which is a digit. So:

            ans = ans * 10 + (s[i] - '0') becomes ans = 0 * 10 + (4) = 4.

            Increment i to 2.

        The next character is '2', which is a digit:

            ans = ans * 10 + (s[i] - '0') becomes ans = 4 * 10 + (2) = 42.

            Increment i to 3.

        Now, i = 3, and since s[i] is out of bounds (end of the string), the loop exits.

    Returning Result:
        The result ans is 42 and sign is -1, so the result is -42.

Final Output:
The function returns -42.
*/
