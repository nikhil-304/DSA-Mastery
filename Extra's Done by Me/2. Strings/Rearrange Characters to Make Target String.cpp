#include <bits/stdc++.h>

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> freqOfs;
        unordered_map<char, int> freqOftarget;
        
        // Count frequency of each character in 's'
        for(char c : s){
            freqOfs[c]++;
        }
        
        // Count frequency of each character in 'target'
        for(char c : target){
            freqOftarget[c]++;
        }
        
        int result = INT_MAX;
        
        // For each character in the target string,
        // calculate how many times it can appear
        for(char c : target){
            if(freqOfs.find(c) == freqOfs.end()) {
                return 0;
            }
            // Find how many times we can use this character
            int maxPossible = freqOfs[c] / freqOftarget[c];
            result = min(result, maxPossible);
        }
        
        return result;
    }
};

//Problem Link: https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/

/*
Time Complexity: O(n + m), where n is the length of s and m is the length of target.
Space Complexity: O(n + m)
*/
