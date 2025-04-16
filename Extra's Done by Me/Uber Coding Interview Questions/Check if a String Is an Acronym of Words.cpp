class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;

        for (int i = 0; i < words.size(); ++i) {
            if (words[i][0] != s[i]) return false;
        }
        return true;
    }
};

//Problem Link: https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        int m = s.size();

        if(n != m) return false;

        int wordCnt = 0;
        for(int i=0 ; i<n ; i++){
            string current = words[i];

            int j = 0;
            bool found = false;

            while(j < current.size()){
                if(current[j] == s[wordCnt]){
                    found = true;
                    break;
                }
                j++;
            }
            if(found == false) return false;
            wordCnt++;
        }
        return true;
    }
};
*/

/*
A generalized solution I developed (my own work)
Time Complexity: O(sum of word lengths)	O(n)
Space Complexity: O(1) (no extra space used)
*/
