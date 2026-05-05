class Solution {
public:
    //Multisource BFS Solution
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                //first row, first col, last row, last col
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        //Push to queue for further operation
                        q.push({i, j});
                        //Mark as visited
                        vis[i][j] = 1;
                    }
                }
            }
        }

        // Direction arrays (Up, Down, Left, Right)
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //check for valid top, bottom, left, right
            for(int d=0 ; d<4 ; d++){
                int nRow = row + delRow[d];
                int nCol = col + delCol[d];

                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   vis[nRow][nCol] == 0 &&
                   grid[nRow][nCol] == 1
                ){
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        //Traverse the grid to find out remaining land cell (1)
        //that is not connected to the boundary.
        //That count is actually the count which cannot walk off 
        //the boundary of the grid.
        int cnt = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};

/*
Problem link: 
Leetcode: https://leetcode.com/problems/number-of-enclaves/
Code360: https://www.naukri.com/code360/problems/matrix-traps_8365440
*/

/*
Time Complexity: O(n × m)
Space Complexity: O(n × m)
*/

/*
1. Identify Boundary Cells: Scan the boundary of the grid (first row, last row, first column, last column) to find all 'land' cells (represented by 1).

2. Initialize Queue and Visited Array: Create a visited vector to track visited cells and a queue to hold the coordinates of boundary land cells.

3. Perform Multi-source BFS: Starting from all boundary land cells in the queue, perform a Breadth-First Search to find all other land cells connected to them.

4. Mark Connected Land Cells: As you traverse, mark all reachable land cells as visited because they can walk off the boundary.

5. Count Non-Boundary Cells: Iterate through the entire grid. Any land cell (1) that is not marked as visited is an enclave (cannot walk off the boundary). Increment a counter for these cells.

6. Return Result: Return the total count of enclaves.
*/

/*
---------------- DFS SOLUTION ----------------
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int d = 0; d < 4; d++) {
            int nRow = row + delRow[d];
            int nCol = col + delCol[d];

            if(nRow >= 0 && nRow < n &&
               nCol >= 0 && nCol < m &&
               !vis[nRow][nCol] &&
               grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, grid, vis, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Run DFS from boundary land cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(grid[i][j] == 1 && !vis[i][j]) {
                        dfs(i, j, grid, vis, n, m);
                    }
                }
            }
        }

        // Count unvisited land cells
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};
*/
