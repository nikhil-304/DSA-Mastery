class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        // Calculate the total sum of the array
        for(int num : nums){
            totalSum += num;
        }

        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++){
            // Right sum is the total sum minus left sum and current element
            int rightSum = totalSum - leftSum - nums[i];

            if(leftSum == rightSum){
                return i;
            }

            // Update left sum for the next iteration
            leftSum += nums[i];
        }
        return -1;
    }
};

//Problem Link: https://leetcode.com/problems/find-pivot-index/description/

/*
Time Complexity: O(2n) ~ O(n)
Space Complexity: O(1)
*/
