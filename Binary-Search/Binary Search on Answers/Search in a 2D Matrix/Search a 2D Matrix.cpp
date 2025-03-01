class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sizeOfRow = matrix.size();
        int sizeOfCol = matrix[0].size();

        int low = 0, high = sizeOfRow * sizeOfCol - 1;
        //Here "high" means the no. of elem in the matrix

        while(low <= high){
            int mid = (low + high) / 2;

            //Hypothetically flatten the 2D array into a 1D array
            int row = mid / sizeOfCol;
            int col = mid % sizeOfCol;
            //This operation flattens down to the coordinates of that elem

            //Normal Binary Search
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(log(m * n))
You're performing binary search on a 1D array of size m * n (which is equivalent to the total number of elements in the 2D matrix).
Binary search has a time complexity of O(log N), where N is the size of the array.

Space Complexity: O(1)
*/

/*
1  4  7  11
2  5  8  12     This matrix is 4 rows and 4 columns.
3  6  9  16
10 13 14 17

Flattening the Matrix into a 1D Array:
[1, 4, 7, 11, 2, 5, 8, 12, 3, 6, 9, 16, 10, 13, 14, 17]
Now, this is a 1D array with 16 elements.

int row = mid / sizeOfCol;
int col = mid % sizeOfCol;

mid is the index in the 1D array that you are considering during binary search.
sizeOfCol is the number of columns in the matrix (in this case, 4).
row and col are the 2D matrix coordinates that correspond to this 1D index.

At index mid = 5, the corresponding element in the matrix is 5.
Now let’s compute the row and column:

    Row Calculation: row = mid / sizeOfCol
        row = 5 / 4 = 1 (integer division)
        So, the row index is 1.

    Column Calculation: col = mid % sizeOfCol
        col = 5 % 4 = 1 (remainder of division)
        So, the column index is 1.

Thus, mid = 5 in the 1D array corresponds to matrix[1][1], which is the value 5.
*/
