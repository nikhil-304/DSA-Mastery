class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        
        queue<pair<int,int>> rottenQueue;
        int freshCount = 0;
        
        // Step 1: Count fresh oranges and store rotten ones
        for(int row = 0; row < totalRows; row++) {
            for(int col = 0; col < totalCols; col++) {
                
                if(grid[row][col] == 2) {
                    rottenQueue.push({row, col});
                }
                else if(grid[row][col] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If no fresh oranges exist
        if(freshCount == 0) return 0;
        
        int minutes = 0;
        
        // Direction arrays (Up, Down, Left, Right)
        int rowDirection[4] = {-1, 1, 0, 0};
        int colDirection[4] = {0, 0, -1, 1};
        
        // Step 2: BFS
        while(!rottenQueue.empty() && freshCount > 0) {
            
            int currentLevelSize = rottenQueue.size();
            minutes++;
            
            for(int i = 0; i < currentLevelSize; i++) {
                
                pair<int,int> currentOrange = rottenQueue.front();
                rottenQueue.pop();
                
                int currentRow = currentOrange.first;
                int currentCol = currentOrange.second;
                
                // Check 4 directions
                for(int d = 0; d < 4; d++) {
                    
                    int newRow = currentRow + rowDirection[d];
                    int newCol = currentCol + colDirection[d];
                    
                    // Check valid cell
                    if(newRow >= 0 && newRow < totalRows &&
                    newCol >= 0 && newCol < totalCols &&
                    grid[newRow][newCol] == 1) {
                        
                        grid[newRow][newCol] = 2; // Make rotten
                        freshCount--;
                        rottenQueue.push({newRow, newCol});
                    }
                }
            }
        }
        
        if(freshCount == 0) return minutes;
        else return -1;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/rotting-oranges/
Code360: https://www.naukri.com/code360/problems/rotting-oranges_6231259
https://www.naukri.com/code360/problems/rotting-oranges_701655
https://www.naukri.com/code360/problems/rotten-oranges_277629
*/

/*
1. Count all fresh oranges.
2. Push all rotten oranges into queue.
3. Do BFS level by level.
4. Each level = 1 minute.
5. Stop when:
    - No fresh left ? return minutes
    - Queue empty but fresh left ? return -1
*/

/*
First Loop (Counting fresh + pushing rotten):
for(row)
    for(col)

BFS Part:
while(queue not empty)
    for(size of queue)
        check 4 directions
*/

/*
Direction array analogy:
// Direction arrays (Up, Down, Left, Right)
int rowDirection[4] = {-1, 1, 0, 0};
int colDirection[4] = {0, 0, -1, 1};

               Example Matrix
                  [0,0,0]
                  [0,2,0]
                  [0,0,0]

                   (0, 1)
                {row-1, col}
                     |     
{row, col-1}  <---  [2] --->  {row, col+1}
   (1,0)           (1,1)         (1, 2)
                     |
                {row+1, col} 
                   (2, 1)

*/

/*
Time Complexity = O(n*m)
Space Complexity = O(n*m)
*/
