class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0) return true;  // Handle zero case
        if(num == 1) return true;  //Handle one case
        int low = 1;
        int high = num;

        while(low <= high){
            int mid = low + (high - low) / 2;

            // Use long long for the multiplication to avoid overflow
            long long midSquared = (long long)mid * mid;

            if (midSquared == num) return true;
            else if (midSquared > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/valid-perfect-square/
Code360: https://www.naukri.com/code360/problems/valid-perfect-square_1082552
*/

/*
Time Complexity: O(log N)
Space Complexity: O(1)
*/
