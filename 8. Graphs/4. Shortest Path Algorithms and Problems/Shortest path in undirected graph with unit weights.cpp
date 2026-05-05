vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    // Step 1: Create adjacency list for the graph
    // We are using an undirected graph, so we add both directions
    vector<vector<int>> adj(N);
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Initialize distance array with "infinity"
    // This represents that initially all nodes are unreachable
    vector<int> dist(N, 1e9);

    // Distance of source node from itself is always 0
    dist[src] = 0;

    // Step 3: BFS queue
    // BFS ensures shortest path in an unweighted graph
    queue<int> q;
    q.push(src);

    // Step 4: Perform BFS traversal
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Traverse all adjacent nodes
        for (auto neighbor : adj[node]) {
            // If a shorter path is found
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Step 5: Prepare final answer
    // Replace unreachable nodes (still at infinity) with -1
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) {
        if (dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}


/*
==================== DRY RUN ====================

Graph Input:
N = 5, M = 4
edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,4}
}
src = 0

Step 1: Adjacency List
0 -> [1, 2]
1 -> [0, 3]
2 -> [0, 4]
3 -> [1]
4 -> [2]

Step 2: Initialize
dist = [0, INF, INF, INF, INF]
queue = [0]

-----------------------------------------
Iteration 1:
node = 0

Neighbors: 1, 2
dist[1] = 1 ? push 1
dist[2] = 1 ? push 2

dist = [0, 1, 1, INF, INF]
queue = [1, 2]

-----------------------------------------
Iteration 2:
node = 1

Neighbors: 0, 3
0 already visited
dist[3] = 2 ? push 3

dist = [0, 1, 1, 2, INF]
queue = [2, 3]

-----------------------------------------
Iteration 3:
node = 2

Neighbors: 0, 4
0 already visited
dist[4] = 2 ? push 4

dist = [0, 1, 1, 2, 2]
queue = [3, 4]

-----------------------------------------
Iteration 4:
node = 3 ? no update
Iteration 5:
node = 4 ? no update

-----------------------------------------
Final dist array:
[0, 1, 1, 2, 2]

Final answer (same as dist since all reachable):
[0, 1, 1, 2, 2]

================================================
*/
