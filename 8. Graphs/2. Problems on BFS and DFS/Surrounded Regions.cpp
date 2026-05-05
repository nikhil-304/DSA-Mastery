class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delRow[], int delCol[]){
        //Mark as visited
        vis[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        //check for valid top, bottom, left, right
        for(int d=0 ; d<4 ; d++){
            int nRow = row + delRow[d];
            int nCol = col + delCol[d];

            if(nRow >= 0 && nRow < n && 
               nCol >= 0 && nCol < m &&
               !vis[nRow][nCol] &&
               board[nRow][nCol] =='O'
            ){
                dfs(nRow, nCol, vis, board, delRow, delCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // Direction arrays (Up, Down, Left, Right)
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        //Traversal for boundary first col and last col
        for(int j=0 ; j<m ; j++){
            // first col
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis, board, delRow, delCol);
            }
            //last col
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, vis, board, delRow, delCol);
            }
        }

        //Traversal for boundary first row and last row
        for(int i=0 ; i<n ; i++){
            // first row
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board, delRow, delCol);
            }
            //last col
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, vis, board, delRow, delCol);
            }
        }

        //Convert 'O' -> 'X'
        //For the remaining 'O's which don't lie in boundaries
        //That means, these O's are surrounded inside with 'X's
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

//Problem link: https://leetcode.com/problems/surrounded-regions/

/*
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

/*
Algorithm Steps

1. Traverse Boundaries: Iterate through the first row, last row, first column, and last column of the matrix.

2. Mark Boundary O's: For any boundary cell containing an 'O', perform a DFS (or BFS) to find all connected 'O's.

3. Identify 'Safe' O's: Mark all 'O's connected to boundary 'O's as 'visited'. These 'O's cannot be surrounded by 'X's.

4. Replace Remaining O's: Iterate through the entire matrix. Any 'O' that is not marked as 'visited' (meaning it was not connected to the boundary) must be converted to an 'X'.

Edge Cases & Considerations

1. O's on the Boundary: Any 'O' on the boundary, or connected to one, must remain 'O'.

2. Diagonal Connections: Diagonal connections are not considered when determining if 'O's are surrounded. Only top, bottom, left, and right directions matter.

3. No Surrounded Regions: The matrix might contain only 'X's, or 'O's only on the boundary, meaning no replacements are needed.
*/

/*
Set of 'O' connected to a boundary cannot be converted to 'X'
eg:
                  X X X X
                  X X X X
 Boundary ----->  O O O X
                  X O O X
                  X X X X

1.) Start from the boundary 'O' and mark them that they'll not be converted & convert the remaining 'O's
*/

/*
------------- BFS SOLUTION ----------------

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delRow[], int delCol[]) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int d = 0; d < 4; d++) {
                int nRow = r + delRow[d];
                int nCol = c + delCol[d];

                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   !vis[nRow][nCol] &&
                   board[nRow][nCol] == 'O') {

                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // First row & last row
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && board[0][j] == 'O') {
                bfs(0, j, vis, board, delRow, delCol);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                bfs(n-1, j, vis, board, delRow, delCol);
            }
        }

        // First col & last col
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && board[i][0] == 'O') {
                bfs(i, 0, vis, board, delRow, delCol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                bfs(i, m-1, vis, board, delRow, delCol);
            }
        }

        // Convert remaining 'O' to 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
*/
