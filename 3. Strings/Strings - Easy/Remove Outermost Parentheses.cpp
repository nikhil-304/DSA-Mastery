class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int cnt = 0;  

        for(char ch : s){
            if(ch == ')') cnt--;
            if(cnt != 0) result += ch;
            if(ch == '(') cnt++;
        }
        return result;
    }
};

//Problem Link: https://leetcode.com/problems/remove-outermost-parentheses/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

//Simple but confusing, do a dry run then you'll understand everything :)

