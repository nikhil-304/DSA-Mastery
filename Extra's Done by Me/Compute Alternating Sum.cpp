class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();
        int alterSum = 0;

        for(int i=0 ; i<n ; i++){
            if(i % 2 == 0){
                alterSum += nums[i];
            }
            else{
                alterSum -= nums[i];
            }
        }
        return alterSum;
    }
};

//Problem Link: https://leetcode.com/problems/compute-alternating-sum/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
