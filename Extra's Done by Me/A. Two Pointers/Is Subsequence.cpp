class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};

/*
Problem Link: 
Leetcode: https://leetcode.com/problems/is-subsequence/description/
Code360: https://www.naukri.com/code360/problems/is-subsequence_892991
*/

/*
Time Complexity: O(|s| + |t|)
Space Complexity: O(1)
*/
