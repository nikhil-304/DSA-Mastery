class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        //If the array is 7 length and we again do it 7 then it'll be same. so for if k=15 there is 7+7+(1) so only consider 1 Rotation
        
        vector<int> temp(k);
        
        for (int i = 0; i < k; i++) {
            temp[i] = nums[nums.size() - k + i];  // Copy the last k elements into temp
        }

        // Step 2: Shift the remaining elements to the right
        for (int i = nums.size() - 1; i >= k; i--) {
            nums[i] = nums[i - k];  // Shift elements to the right by k positions
        }

        // Step 3: Copy the elements from temp back to the beginning of nums
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];  // Place the last k elements at the front
        }
    }
};

//Problem Link: https://leetcode.com/problems/rotate-array/

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); // In case k is larger than the size of the array
        
        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};
*/
