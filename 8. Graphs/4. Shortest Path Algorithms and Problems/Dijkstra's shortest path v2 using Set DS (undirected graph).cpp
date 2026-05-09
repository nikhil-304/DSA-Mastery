vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Adjacency list
    vector<vector<pair<int, int>>> adj(vertices);

    // Build Adjacency list
    for(int i=0 ; i<edges ; i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    // Set to store pairs: {distance, node}
    set<pair<int, int>> st;

    // Distance array initialized to infinity
    vector<int> dist(vertices, INT_MAX);

    // Initial configuration for source node
    dist[source] = 0;
    st.insert({0, source});

    // Travel to adjacent nodes
    while(!st.empty()){
        auto it = *(st.begin()); // st.begin() gives the address, "*" gives the value at address
        int dis = it.first;
        int node = it.second;

        st.erase(it);

        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            
            // Relaxation step: check if a shorter path is found
            if(dis + edgeWeight < dist[adjNode]){
                // erase if it existed *****
                if(dist[adjNode] != INT_MAX){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

//Problem Link: https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_985358

/*
*****
Example
Suppose:

dist[5] = INT_MAX

First time reaching node 5:

dist[5] = 12
st.insert({12,5});

No old value existed, so no erase needed.

Later:
new distance = 8

Now:
st.erase({12,5});
dist[5] = 8;
st.insert({8,5});

This keeps only the latest shortest distance in the set.

--------------------------------------------------

but what if we don't erase then? any issue?
Yes - the algorithm will still produce the correct shortest distances, but the set will contain multiple outdated entries for the same node, making it less efficient.

Example:

Instead of:
{7, 3}

the set may contain:
{10, 3}
{7, 3}

Both entries remain.

What happens then?

When {7,3} is processed first:

node 3 gets relaxed correctly.

Later {10,3} is popped:

it is an outdated state,
but your code still traverses neighbors again.

This causes:

unnecessary work,
extra relaxations,
slower performance.
Why correctness still works

Because of this condition:

if(dis + edgeWeight < dist[adjNode])

Suppose:

current best dist[3] = 7
outdated entry popped is {10,3}

Then:

10 + edgeWeight < dist[adjNode]

usually fails because 10 is already worse than the stored shortest distance.

So no incorrect updates happen.

What changes in complexity?
With erase (your current code)

Each node keeps only its latest best distance in the set.

Complexity roughly:

O((V + E) log V)
Without erase

Set may accumulate many stale entries.

Complexity can degrade toward:

O(E log E)

or worse in dense graphs.

Still accepted in many coding problems, but less optimal.
*/
