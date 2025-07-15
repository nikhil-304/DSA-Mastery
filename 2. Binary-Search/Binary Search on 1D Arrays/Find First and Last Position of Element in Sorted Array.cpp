int firstOccurence(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int first = -1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            first = mid;      //Need to check 1st occ so eliminate right side
            high = mid - 1;   //Check in the left
        }
        else if(nums[mid] < target){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int last = -1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target){ 
            last = mid;        //Need to check last occ so eliminate left side
            low = mid+1;       //Check in the right
        }
        else if(nums[mid] < target){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurence(nums, target);
        if(first == -1) return {-1, -1};  //Saving another O(logn) if occ not found
        int last = lastOccurence(nums, target);
        return {first, last};
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Code360: https://www.naukri.com/code360/problems/frequency-in-a-sorted-array_893286
*/

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
