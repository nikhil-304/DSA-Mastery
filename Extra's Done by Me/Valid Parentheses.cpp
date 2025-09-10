class Solution {
public:
    bool isValid(const string &s) {
        // Map from closing bracket to its corresponding opening bracket
        unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        stack<char> st;
        for (char c : s) {
            // If it's an opening bracket, push
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // It's a closing bracket
                if (st.empty()) {
                    return false;  // no matching opening bracket
                }
                char topChar = st.top();
                st.pop();
                // Check if it matches
                if (matching[c] != topChar) {
                    return false;
                }
            }
        }
        // In the end, stack should be empty
        return st.empty();
    }
};

//Problem Link: https://leetcode.com/problems/valid-parentheses/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
