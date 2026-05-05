class Solution {
private:
    bool dfs(int node, int color, vector<int> &vis, vector<vector<int>> &adj){
        //Mark as visited - Assign current node a color (0 or 1)
        vis[node] = color;

        // Traverse all neighbors
        for(auto neighbor : adj[node]){
            // If neighbor is not visited, assign opposite color
            if(vis[neighbor] == -1){
                if(dfs(neighbor, !color, vis, adj) == false)
                    return false;
            }
            // If neighbor already has same color -> not bipartite
            else if(vis[neighbor] == color) return false;
        }
        // No conflicts found
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // Initialize all nodes as unvisited (-1)
        vector<int> colorTrack(n, -1);

        for(int i=0 ; i<n ; i++){
            if(colorTrack[i] == -1){
                // Start DFS with color 0
                if(dfs(i, 0, colorTrack, graph) == false)
                    return false;
            }
        }
        return true;
    }
};

// Problem Link: https://leetcode.com/problems/is-graph-bipartite/

/*
Time Complexity: O(V + 2E)
Space Complexity: O(V)
*/

/*
-------------- Bipartite Graph Theory ---------------

- Definition: A bipartite graph is a graph that can be colored using exactly two colors (e.g., Yellow and Green) such that no two adjacent nodes share the same color.

- Odd Length Cycles: A graph is bipartite if and only if it does not contain any odd-length cycles. If an odd-length cycle exists, it is impossible to color the graph with only two colors without violating the adjacency rule.

- Even Length Cycles & Linear Graphs: Graphs with only even-length cycles or simple linear paths are bipartite.

----------------- DFS Coloring Algorithm --------------------

1. Initialization: Create a color array of size V initialized to -1 (uncolored). Use 0 and 1 to represent the two colors.

2. Coloring Logic: Start DFS from a node, coloring it 0. For any uncolored neighbor, color it with the opposite color.

3. Checking Condition: If you encounter an adjacent node that is already colored with the same color as the current node, the graph is not bipartite (return false).
*/