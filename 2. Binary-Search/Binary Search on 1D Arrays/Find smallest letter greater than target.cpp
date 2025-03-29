class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1;
        char ans = letters[0]; 
        //If no letter greater than target return 1st letter

        while (low <= high) {
            int mid = (low + high) / 2;
            if (letters[mid] > target) {
                ans = letters[mid]; // Possible answer, but search for smaller
                high = mid - 1;
            } else {
                low = mid + 1; // Search right side
            }
        }
        return ans;
    }
};

//Problem Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
