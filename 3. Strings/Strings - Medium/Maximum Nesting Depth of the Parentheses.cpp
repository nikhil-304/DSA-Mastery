class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int tempCnt = 0;

        for(char ch : s){
            if(ch == '('){
                cnt++;
                tempCnt = max(cnt, tempCnt);
            }
            if(ch == ')') cnt--;
        }
        return tempCnt;
    }
};

//Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
