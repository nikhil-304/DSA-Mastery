#include <bits/stdc++.h> 
void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    //n is row & m is column
    //Row marking [i][0]
    //Column marking [0][j]
    int col0 = 0;

    // Marking of 1's in the Matrix
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(MAT[i][j] == 1){
                //Row Marking
                MAT[i][0] = 1;

                //Col Marking
                if(j != 0){
                    MAT[0][j] = 1;
                }
                else col0 = 1;
            }
        }
    }

    //Acc to markings, replacing the whole row or col
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<m ; j++){
            if(MAT[i][j] != 1){
                if(MAT[i][0] == 1 || MAT[0][j] == 1){
                    MAT[i][j] = 1;
                }
            }
        }
    }

    //Handling Edge Cases
    if(MAT[0][0] == 1){
        for(int j=0 ; j<m ; j++){
            MAT[0][j] = 1;
        }
    }

    if(col0 == 1){
        for(int i=0 ; i<n ; i++){
            MAT[i][0] = 1;
        }
    }
}

//Problem Link: https://www.naukri.com/code360/problems/set-matrix-ones_981213

/*
This is for 0's but same is applicable on 1's too.
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

