class Solution {
public:
    string intToRoman(int num) {
        // Pair of integer values and corresponding Roman numerals
        vector<pair<int, string>> romanNumerals = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        
        for (auto& pair : romanNumerals) {
            int value = pair.first;
            string symbol = pair.second;
            
            // Subtract the value from num as many times as possible
            while (num >= value) {
                result += symbol; // Add the Roman symbol to the result
                num -= value;     // Subtract the value from num
            }
        }
        return result;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/integer-to-roman/description/
Code360: https://www.naukri.com/code360/problems/integer-to-roman-numeral_981307
*/

/*
Time Complexity: O(1) (constant time), because the number of Roman numeral pairs is fixed, and the number of iterations is bounded.

Space Complexity: O(1) (constant space), because the space used by the input, output, and auxiliary variables is constant and does not depend on the input size.
*/

/*
For the input num = 3749:

    3749 >= 1000 ? Add "M" and subtract 1000 ? 3749 - 1000 = 2749
    2749 >= 1000 ? Add "M" and subtract 1000 ? 2749 - 1000 = 1749
    1749 >= 1000 ? Add "M" and subtract 1000 ? 1749 - 1000 = 749
    749 >= 500 ? Add "D" and subtract 500 ? 749 - 500 = 249
    249 >= 100 ? Add "C" and subtract 100 ? 249 - 100 = 149
    149 >= 100 ? Add "C" and subtract 100 ? 149 - 100 = 49
    49 >= 40 ? Add "XL" and subtract 40 ? 49 - 40 = 9
    9 >= 9 ? Add "IX" and subtract 9 ? 9 - 9 = 0

So, the Roman numeral for 3749 is "MMMDCCXLIX".
*/
