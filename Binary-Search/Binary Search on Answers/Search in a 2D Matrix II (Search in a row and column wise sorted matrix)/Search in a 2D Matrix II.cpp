class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n+m)
Space Complexity: O(1)
*/

/*
Here the approach is as follows:
    1.) We start at 15, and observe that left to 15 elements are smaller
    and down to 15 elements are bigger.
    2.) So we traverse down like this.
        - Suppose we want to find element 14
        - We start at 15. is 15 < 14? No, so we eliminate the down part
        of 15 as down there, it'll be bigger elements only. 
        - So col-- and we now stand at 11.
        - Now, is 11 < 14, Yes... so as left of 11 will have smaller elemns
        we do a row++.
    3.) And continue so on, untill you find the element.

See the video for a better visual understanding.
Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/
*/
