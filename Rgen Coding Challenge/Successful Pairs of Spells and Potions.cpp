class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairsCount;
        int m = potions.size();
        
        for(int spell : spells) {
            // Calculate the minimum potion strength needed
            long long minPotionThreshold = (success + spell - 1) / spell;
            
            // Use binary search to find the first sufficient potion
            auto firstPotionOcc = lower_bound(potions.begin(), potions.end(), minPotionThreshold);
            
            // Count how many potions are sufficient
            int count = potions.end() - firstPotionOcc;
            pairsCount.push_back(count);
        }
        return pairsCount;
    }
};

//Problem Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

/*
Time Complexity: O(m log m + n log m)
Space Complexity: O(n)
*/
