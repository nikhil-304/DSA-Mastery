class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int cnt_max = 0;
        int indexRow = 0;

        // Iterate over each row
        for (int i = 0; i < row; i++) {
            int cnt_ones = count(mat[i].begin(), mat[i].end(), 1); // Count the number of ones directly in the row
            if (cnt_ones > cnt_max) {  // Update if we find more ones
                cnt_max = cnt_ones;
                indexRow = i; // Save the row index with max ones
            }
        }

        // Return the index of the row and the count of ones in that row
        return {indexRow, cnt_max};
    }
};

/*
Time Complexity: O(M * N), where M is the number of rows and N is the number of columns in the matrix.
Space Complexity: O(1)

Problem Link: https://leetcode.com/problems/row-with-maximum-ones/description/
*/
