class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0 ; i<2*n ; i++){
            if(i < n){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(nums[i - n]);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
Approach

Suppose we have an array nums = [1, 2, 1] with indices:
[1, 2, 1]
0--1--2
To concatenate the array, we want to repeat its elements after the last index.

For example:

    The 3rd index will have the 0th element (1).
    The 4th index will have the 1st element (2).
    The 5th index will have the 2nd element (1).

The idea is to loop through the array twice. In the first pass, we add the elements from the original array. Then, once we reach i = n (where n is the size of nums), we start adding the same elements again by using i - n (i.e., we start over from the beginning of nums).

Example:
For nums = [1, 2, 1]:

    When i = 0, 1, 2, we add nums[i] to ans (result: [1, 2, 1]).
    When i = 3, 3 - 3 = 0, so we add nums[0] (result: [1, 2, 1, 1]).
    When i = 4, 4 - 3 = 1, so we add nums[1] (result: [1, 2, 1, 1, 2]).
    When i = 5, 5 - 3 = 2, so we add nums[2] (result: [1, 2, 1, 1, 2, 1]).

This creates the concatenated array [1, 2, 1, 1, 2, 1].

Since the result array ans is twice the size of nums (i.e., 2 * n), we get the final concatenated array after the loop runs.
*/
