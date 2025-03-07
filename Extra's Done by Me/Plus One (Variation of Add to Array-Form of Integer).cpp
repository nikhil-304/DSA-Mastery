class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;  // Simply add 1 and return the result
                return digits;
            }
            digits[i] = 0;  // If the digit is 9, set it to 0 and continue
        }
        
        // If all digits are 9, we need to add an extra leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

//Problem Link: https://leetcode.com/problems/plus-one/

/*
Time complexity: O(n)
Space complexity: O(1) if no insertion happens (just modifying the existing vector).
O(n) if the insertion of the 1 occurs, as a new element is added to the vector.
*/

/*
Example:
Input: digits = [1, 2, 3]

    No carry, so simply increment the last digit to [1, 2, 4].

Input: digits = [4, 3, 2, 1]

    No carry, so simply increment the last digit to [4, 3, 2, 2].

Input: digits = [9]

    The last digit is 9, so it becomes 0 and we add a leading 1: [1, 0].

Input: digits = [9, 9, 9]

    All digits are 9, so we turn them into 0s and insert a leading 1: [1, 0, 0, 0].
*/


//My approach inspired by `Add to Array-Form of Integer` :)
/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = 1;
        vector<int> result;
        int n = digits.size();

        for(int i=n-1 ; i>=0 || k>0 ; i--){
            if(i >= 0) k += digits[i];

            result.push_back(k % 10);
            k = k/10;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
*/
/*
Time Complexity: O(n), where n is the length of the input digits array.
Space Complexity: O(n), due to the storage of the result vector.
*/
