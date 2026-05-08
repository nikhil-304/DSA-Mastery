#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Adjacency list
    vector<vector<pair<int,int>>> adj(vertices);

    // Build graph
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected graph
    }
    
    // Min-heap to store pairs: {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Distance array initialized to infinity
    vector<int> dist(vertices, INT_MAX);

    // Initial configuration for source node
    dist[source] = 0;
    pq.push({0, source});

    // Travel to adjacent nodes
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            // Relaxation step: check if a shorter path is found
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }

        }
    }
    return dist;
}

//Problem Link: https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469
