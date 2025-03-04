// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid - 1;  // Look for an earlier bad version
            } else {
                low = mid + 1;   // Move to later versions
            }
        }
        return low;  // `low` will be the first bad version
    }
};

/*
Time Complexity: O(logn)
Space Complexity: O(1)
*/


//Problem Link: https://leetcode.com/problems/first-bad-version/description/
