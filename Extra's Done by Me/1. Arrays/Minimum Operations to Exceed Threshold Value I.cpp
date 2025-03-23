class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i=0 ; i<n ; i++){
            if(nums[i] < k){
                cnt++;
            }
        }
        return cnt;
    }
};

//Problem Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
