class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int left = 0;
        int right = n-1;

        while(left <= right){
            if(numbers[left] + numbers[right] == target){
                return {left+1, right+1};
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else left++;
        }
        return {-1, -1};
    }
};

/*
Problem Link: 
LeetCode: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Code360: https://www.naukri.com/code360/problems/two-sum_4244495
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
