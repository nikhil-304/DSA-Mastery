class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;

        for(char c : s){
            if(seen.find(c) != seen.end()) {
                return c; // return the first character that repeats
            }
            seen.insert(c); // Add the character to the set
        }
        
        return 0;
    }
};

//Problem Link: https://leetcode.com/problems/first-letter-to-appear-twice/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
