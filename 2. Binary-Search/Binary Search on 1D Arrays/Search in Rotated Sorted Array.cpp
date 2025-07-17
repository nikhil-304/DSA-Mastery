class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            //Left Half Sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;  //Eliminate Right Side
                }
                else{
                    low = mid + 1;   //Eliminate Left Side
                }
            }
            //Right Half Sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;   //Eliminate Left Side
                }
                else{
                    high = mid - 1;  //Eliminate Right Side
                }
            }
        }
        return -1;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/
Code360: https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_630450
*/

/*
Time Complexity: O(logn)
Space Complexity: O(1)
*/

/*
Firstly, identify the sorted halves. (You'll get only 1 sorted part at first)
Check if the key element falls within the sorted half.
if no then check other side.
*/
