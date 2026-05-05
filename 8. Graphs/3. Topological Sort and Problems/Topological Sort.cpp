class Solution
{
  private:
    // DFS function to explore graph and fill stack
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj){
        
        // Mark current node as visited
        vis[node] = 1;
        
        // Traverse all adjacent nodes (neighbors)
        for(auto it : adj[node]){
            
            // If neighbor is not visited, perform DFS on it
            if(!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        
        // After visiting all neighbors, push current node into stack
        // This ensures dependencies are handled first
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int n, vector<vector<int>> adj){
        
        // Visited array to track visited nodes
        vector<int> vis(n, 0);
        
        // Stack to store the topological order
        stack<int> st;
        
        // Loop through all nodes (important for disconnected graph)
        for(int i = 0; i < n; i++){
            
            // If node is not visited, start DFS from it
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        // Vector to store final topological order
        vector<int> ans;
        
        // Pop elements from stack to get correct order
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        // Return the topological sorted order
        return ans;
    }
};

/*
Topological sorting is defined as a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge from vertex U to vertex V, U always appears before V in the ordering. It only exists in directed acyclic graphs because any cyclic dependency would make it impossible to establish a linear sequence where all conditions are met

The DFS-based algorithm traverses the graph, and only when a node has no more unvisited neighbors does it push that node onto a stack. This ensures that nodes with no remaining dependencies are placed at the bottom, and nodes that must come first are placed at the top of the stack.

Final Topological Sort Linear Result

After performing the DFS traversal and popping the elements from the stack one by one, we get this valid linear ordering:

5, 4, 2, 3, 1, 0

Why this is valid:

    5 appears before 0 and 2.
    4 appears before 0 and 1.
    2 appears before 3.
    3 appears before 1.

Because every directed edge U ? V respects the rule that U comes before V in the sequence, this is a correct topological sort of the graph.
*/

/*
INTUITION OF DFS TOPOLOGICAL SORT

1. Problem Understanding:
   - We need to order nodes such that:
     If there is an edge u ? v,
     then u must come BEFORE v.

2. Core Idea:
   - "Finish all dependencies first, then add the node"

3. How DFS helps:
   - DFS goes deep into graph (dependency chain)
   - It ensures:
        Child (dependency) is processed before parent

4. Key Trick:
   - Push node into stack ONLY AFTER visiting all neighbors

   Why?
   Because:
        neighbor ? processed first
        node ? processed later

5. Stack Role:
   - Stack reverses the order automatically
   - So final order becomes correct topological order

6. Example Thinking:
   Graph:
        1 ? 2 ? 3

   DFS flow:
        dfs(1)
            dfs(2)
                dfs(3)
                    push(3)
                push(2)
            push(1)

   Stack: [3,2,1]
   Answer: [1,2,3]

7. Important Condition:
   - This ONLY works for DAG (no cycles)

8. Time Complexity:
   - O(V + E)
   - Visit every node and edge once

9. Space Complexity:
   - O(V) (visited + stack + recursion stack)
*/
