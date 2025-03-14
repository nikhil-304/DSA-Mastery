class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap;

        for (int num : arr) {
            freqMap[num]++;
        }

        unordered_set<int> seen;
        for (auto& pair : freqMap) {
            if (seen.find(pair.second) != seen.end()) {  
                return false; // If count already exists, return false  
            }
            seen.insert(pair.second);
        }
        return true;
    }
};

//Problem Link: https://leetcode.com/problems/unique-number-of-occurrences/description/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
