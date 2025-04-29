class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int goodPairs = 0;

        unordered_map<int, int> mpp;

        // Count the frequency of each number
        for(auto num : nums){
            mpp[num]++;
        }

        // Calculate the good pairs for each frequency
        for(auto it = mpp.begin() ; it != mpp.end() ; it++){
            int f = it->second;
            if (f >= 2) {
                goodPairs += f * (f - 1) / 2;
            }
        }
        return goodPairs;
    }
};

//Problem Link: https://leetcode.com/problems/number-of-good-pairs/

/*
Time Complexity: O(n)
Space Complexity: O(n),
*/

/*
vector<int> nums = {1, 2, 3, 3, 1};
Iteration 1: it = {1: 2}
    f = 2 (frequency of 1).
    goodPairs += 2 * (2 - 1) / 2 = 2 * 1 / 2 = 1 (1 pair of 1s).
    goodPairs is now 1.

Iteration 2: it = {2: 1}
    f = 1 (frequency of 2).
    f < 2, so no pairs are added for 2.

Iteration 3: it = {3: 2}
    f = 2 (frequency of 3).
    goodPairs += 2 * (2 - 1) / 2 = 2 * 1 / 2 = 1 (1 pair of 3s).
    goodPairs is now 2.

After iterating through the frequency map, goodPairs = 2, which is the correct number of identical pairs in the array [1, 2, 3, 3, 1].

#The formula for pairs:
For any number that appears f times, the number of good pairs (pairs of identical elements) is given by the combination formula:
    f(f-1)/2

This formula counts how many ways we can choose 2 elements from f elements. For example, if a number appears 3 times, there are 3 possible pairs of that number, which is calculated as:
    3(3-1)2=3
*/

//---------------------------------------------------------------------

//Brute Force Solution
/*
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int goodPairs = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(nums[i] == nums[j]){
                    goodPairs++;
                }
            }
        }
        return goodPairs;
    }
};
*/
