vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    // vector to store bfs traversal elements
    vector<int> bfs;
    if (n == 0) return bfs;

    vector<int> vis(n, 0); //To keep a track of the visited node
    queue<int> q;  // Temp queue for helping BFS Traversal

    q.push(0); // Pushing first element
    vis[0] = 1; // 1st node already visited

    while (!q.empty()) {
        int node = q.front(); // Take the first elem
        q.pop(); // Remove it from queue

        bfs.push_back(node); // push it to the vector

        for (int neighbor : adj[node]) {
            // search for its adjacent neighbors
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return bfs;
}

//Problem Link: https://www.naukri.com/code360/problems/bfs-in-graph_973002

/*
Time Complexity: O(N + E)
Space Complexity: O(N)
*/

