class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNums;
        romanNums['I'] = 1;
        romanNums['V'] = 5;
        romanNums['X'] = 10;
        romanNums['L'] = 50;
        romanNums['C'] = 100;
        romanNums['D'] = 500;
        romanNums['M'] = 1000;

        int roman2Int = 0;
        int prevValue = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            int currValue = romanNums[s[i]];

            // If the current value is less than the previous value, subtract it
            if(currValue < prevValue) {
                roman2Int -= currValue;
            } 
            else {
                roman2Int += currValue;
            }
            // Update previous value for next iteration
            prevValue = currValue;
        }
        return roman2Int;
    }
};

//Problem Link: https://leetcode.com/problems/roman-to-integer/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Example Input:

Let’s use the Roman numeral "MCMXCIV".
Roman Numeral Breakdown:

    M = 1000
    C = 100
    M = 1000
    X = 10
    C = 100
    I = 1
    V = 5

Expected Output:
The integer value should be 1994.

        romanNums = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000 }

        roman2Int = 0 (This is where we accumulate the result)

        prevValue = 0 (This tracks the value of the numeral from the previous iteration)

    First Iteration (i = 6, 'V'):
        currValue = romanNums['V'] = 5
        currValue (5) >= prevValue (0), so we add 5 to roman2Int.
        roman2Int = 5
        prevValue = 5 (update prevValue)

    Second Iteration (i = 5, 'I'):
        currValue = romanNums['I'] = 1
        currValue (1) < prevValue (5), so we subtract 1 from roman2Int.
        roman2Int = 5 - 1 = 4
        prevValue = 1 (update prevValue)

    Third Iteration (i = 4, 'C'):
        currValue = romanNums['C'] = 100
        currValue (100) >= prevValue (1), so we add 100 to roman2Int.
        roman2Int = 4 + 100 = 104
        prevValue = 100 (update prevValue)

    Fourth Iteration (i = 3, 'X'):
        currValue = romanNums['X'] = 10
        currValue (10) < prevValue (100), so we subtract 10 from roman2Int.
        roman2Int = 104 - 10 = 94
        prevValue = 10 (update prevValue)

    Fifth Iteration (i = 2, 'M'):
        currValue = romanNums['M'] = 1000
        currValue (1000) >= prevValue (10), so we add 1000 to roman2Int.
        roman2Int = 94 + 1000 = 1094
        prevValue = 1000 (update prevValue)

    Sixth Iteration (i = 1, 'C'):
        currValue = romanNums['C'] = 100
        currValue (100) < prevValue (1000), so we subtract 100 from roman2Int.
        roman2Int = 1094 - 100 = 994
        prevValue = 100 (update prevValue)
    Seventh Iteration (i = 0, 'M'):
        currValue = romanNums['M'] = 1000
        currValue (1000) >= prevValue (100), so we add 1000 to roman2Int.
        roman2Int = 994 + 1000 = 1994
        prevValue = 1000 (update prevValue)

Final Value:

    After iterating through the entire string, roman2Int holds the final result: 1994
*/
