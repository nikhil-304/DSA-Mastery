class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs[0].size(); i++) {
            char currentChar = strs[0][i];

            for (int j = 0; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != currentChar) {
                    return result;
                }
            }
            result += currentChar;
        }
        return result; 
    }
};

//Problem Link: 
//LeetCode: https://leetcode.com/problems/longest-common-prefix/description/
//Code360: https://www.naukri.com/code360/problems/longest-common-prefix_2090383

/*
Time Complexity: O(m*n)
n is the number of strings in strs
m is the length of the shortest string (as the function will stop at the end of the shortest string)

Space Complexity: O(1)
*/

/*
Dry Run:
First Iteration: (i = 0)
currentChar = strs[0][0] = 'f' (the first character of the first string, "flower").

Inner Loop (j = 0 to 2):
j = 0 (first string: "flower")
strs[0][0] = 'f' is compared with currentChar = 'f'. They match.

j = 1 (second string: "flow")
strs[1][0] = 'f' is compared with currentChar = 'f'. They match.

j = 2 (third string: "flight")
strs[2][0] = 'f' is compared with currentChar = 'f'. They match.

Since all strings have 'f' at index 0, the character 'f' is added to the result:

result = "f"
*/

