class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int num : nums){
            mpp[num]++;
        }

        for(auto it = mpp.begin() ; it != mpp.end() ; it++){
            if(it->second > 2){
                return false;
            }
        }
        return true;
    }
};

//Problem Link: https://leetcode.com/problems/split-the-array/description/

/*
Time Complexity: O(n)
Space Complexity: O(k) where k is the number of unique elements, which in the worst case is O(n).
*/

/*
Input: nums = [1,1,2,2,3,4]
    countMap = {1: 2, 2: 2, 3: 1, 4: 1}
    No element appears more than twice, so we can split the array.
    Possible split: nums1 = [1, 2, 3] and nums2 = [1, 2, 4].
Output: true

Example 2:
Input: nums = [1,1,1,1]
    countMap = {1: 4}
    Element 1 appears more than twice, so it is impossible to split the array.
Output: false
*/
