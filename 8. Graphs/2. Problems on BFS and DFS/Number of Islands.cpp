class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        //Mark as visited
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // Direction arrays (Up, Down, Left, Right)
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};

        // Check 4 directions
        for(int d=0 ; d<4 ; d++){
            int nRow = row + delRow[d];
            int nCol = col + delCol[d];

            // Check valid cell
            if(nRow >= 0 && nRow < n &&
               nCol >= 0 && nCol < m &&
               grid[nRow][nCol] == '1' &&
               !vis[nRow][nCol]
            ){
                dfs(nRow, nCol, vis, grid);
            }
        }
        
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                  // Increase count before calling DFS because
                  // DFS will start from one '1' and explore all
                  // connected '1's recursively.
                  // It keeps going deeper until 
                  // no neighboring '1's are found.
                  // All connected '1's together form one island.
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};

//Problem Link: https://leetcode.com/problems/number-of-islands/description/

/*
Time Complexity: O(n × m)
Space Complexity: O(n × m)
*/

/*
Algorithm:
1. Traverse each cell in the grid
2. If cell is '1' and not visited:
   - Increment island count
   - Run DFS to mark all connected '1's
3. DFS explores in 4 directions and marks visited
4. Continue until grid traversal is complete
5. Return total count
*/
