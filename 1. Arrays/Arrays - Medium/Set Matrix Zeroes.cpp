class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //int col[m] = {0}  -> matrix[0][..]
	    //int row[n] = {0}  -> matrix[..][0]

        // row = [i][0]
	    // col = [0][j]

        int n = matrix.size();   //Rows
        int m = matrix[0].size();  //Columns

        int col0 = 1;

        // Marking of 0's in the Matrix
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    //Row Marking
                    matrix[i][0] = 0;
                    //Columns Marking
                    if(j!=0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }

                }
            }
        }

        //Acc to markings, replacing the whole row or col
        for(int i=1 ; i<n ; i++)
        {
            for(int j=1 ; j<m ; j++)
            {
                if(matrix[i][j] != 0)
                {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        //Handling Edge Cases
        if(matrix[0][0] == 0){
            for(int j=0 ; j<m ; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0 ; i<n ; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

/*
Problem Link: 
LeetCode: https://leetcode.com/problems/set-matrix-zeroes/
Code360: https://www.naukri.com/code360/problems/set-matrix-zeros_3846774
*/

/*
Intuition:
Reserve the 0th row and 0th column for marking of 0's
col0 = 1
       --col--
	   1 | 1 1
|	   -------
Row	   1 | 0 1
|	   1 | 1 1

1. The first loop is used to traverse the whole matrix and mark
 if(i, j) is 0:
	[i.] Mark that row and column at 0th row and 0th column
	eg. 1  (0) 1
	   (0)  0  1
		1   1  1

2. Second loop, again traverse the whole matrix but from (1, 1); check 
    eg.     0  1
			1  1
if 0th row or 0th column == 0:
	Mark the whole row or column as 0
	(In this case, the (1, 0) is already 0, so only need to modify (1,2) to 0)
	((0,1) is already 0, so only need to modify (2,1) to 0)

3. Edge Cases:
if matrix[0][0] = 0, mark the whole 0th row to 0
if(col0 = 0), mark the whole 0th col to 0
*/

/*
Time Complexity: O(2(n*m))
Space Complexity: O(1)
*/
