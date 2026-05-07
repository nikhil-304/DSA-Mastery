#include <bits/stdc++.h>

void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto it : adj[node]){
        int v = it.first;

        if(!vis[v]){
            topoSort(v, adj, vis, st);
        }
    }

    // Push current node into stack
    //
    // VERY IMPORTANT:
    //
    // Node is pushed ONLY AFTER
    // all its neighbours are visited.
    //
    // This creates Topological Order.
    //
    // --------------------------------------------------
    // EXAMPLE
    // --------------------------------------------------
    //
    // Graph:
    //
    // 0 ---> 1 ---> 2
    //
    // DFS Flow:
    //
    // topoSort(0)
    //     |
    //     ---> topoSort(1)
    //              |
    //              ---> topoSort(2)
    //
    // Node 2 has no neighbours
    // so:
    //
    // st.push(2)
    //
    // Return back to node 1
    //
    // st.push(1)
    //
    // Return back to node 0
    //
    // st.push(0)
    //
    // Final Stack:
    //
    // TOP
    // 0
    // 1
    // 2
    //
    // When popping:
    //
    // 0 -> 1 -> 2
    //
    // This becomes Topological Order.
    // --------------------------------------------------
    //
    // WHY PUSH AFTER DFS?
    //
    // Because dependency should come first.
    //
    // Example:
    //
    // 0 ---> 1
    //
    // 0 must appear before 1
    //
    // So:
    //
    // visit 1 first
    // push 1
    //
    // then push 0
    //
    // Stack automatically reverses order
    // during popping.
    //
    // --------------------------------------------------
    // IMPORTANT CONCEPT
    //
    // DFS + push after recursion
    // = Topological Sort
    // --------------------------------------------------

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n);

    // Creating adjacency list
    for(int i=0 ; i<m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    vector<int> vis(n, 0);
    stack<int> st;

    // Topological Sort
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(n, 1e9);
    dist[0] = 0; // Source node = 0

    while(!st.empty()){
        int node = st.top();
        st.pop();

        // If current node is reachable from source
        // only then process its neighbours
        //
        // Example:
        // dist = [0, 2, 1, INF]
        //
        // If node = 3 and dist[3] = INF
        // it means node 3 is unreachable,
        // so no need to relax its edges.

        if (dist[node] != 1e9) {
            // Traverse all neighbours of current node
            //
            // Example:
            //
            // adj[0] = { {1,2}, {4,1} }
            //
            // Meaning:
            // 0 -> 1 with weight 2
            // 0 -> 4 with weight 1
            for (auto it : adj[node]) {
                // Destination node
                int v = it.first;
                // Edge weight
                int wt = it.second;

                /*
                RELAXATION STEP

                Check:
                Can we reach neighbour with smaller distance?

                Formula:
                current distance to node + edge weight

                Example:

                dist[0] = 0

                Edge:
                0 -> 1 weight 2

                Then:

                dist[0] + 2 < dist[1]
                0 + 2 < INF

                YES

                So update:
                dist[1] = 2
                */

                if (dist[node] + wt < dist[v]) {
                    // Update shorter distance
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }

    // Convert infinity to -1
    for(int i=0 ; i<dist.size() ; i++){
        if(dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}

//Problem Link: https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897

/*
Innermost
pair<int, int>

Stores:
{neighbour, weight}

Example:
{2, 5}

means:
go to node 2 with weight 5

----------------------------------------------------

Step 2
vector<pair<int, int>>

Means:
A list of neighbour-weight pairs.

Example:
[
   {1,2},
   {4,1},
   {5,7}
]

means:

current node connects to:
1 with weight 2
4 with weight 1
5 with weight 7

-------------------------------------------------------------

Step 3 (FULL)
vector<vector<pair<int, int>>> adj(n);

Means:

adj[0] = list of neighbours of node 0
adj[1] = list of neighbours of node 1
adj[2] = list of neighbours of node 2
...
REAL EXAMPLE

Suppose graph is:

0 ---> 1 (weight 2)
0 ---> 4 (weight 1)
1 ---> 2 (weight 3)
4 ---> 2 (weight 2)

How We Insert
adj[0].push_back({1, 2});
adj[0].push_back({4, 1});
adj[1].push_back({2, 3});
adj[4].push_back({2, 2});

FINAL STORAGE IN MEMORY

adj =
[
   [ {1,2}, {4,1} ],   // adj[0]

   [ {2,3} ],          // adj[1]

   [ ],                // adj[2]

   [ ],                // adj[3]

   [ {2,2} ]           // adj[4]
]
*/

