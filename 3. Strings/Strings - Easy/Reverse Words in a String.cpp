class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        string temp = "";

        for (int i = n - 1; i >= 0; --i) {
            // If the character is not a space, add it to the temp string
            if (s[i] != ' ') {
                temp = s[i] + temp;
            } 
            else {
                if (!temp.empty()) {
                    result += temp + " ";
                    temp = "";
                }
            }
        }
        
        // If there's any word left in temp, add it to the result
        if (!temp.empty()) {
            result += temp;
        }
        
        // Remove any trailing space (if present)
        if (result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};

//Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
