vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t) {
    
    // Build Adjacency List
    vector<vector<int>> adj(n + 1);
    for (auto it : edges) {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    // Only track visited
    vector<int> visited(n + 1, 0);

    // Parent array (important)
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1;
                // I reached "it" from "node"
                // eg. 2 -> came from 1
                // 3 -> came from 1
                parent[it] = node;
                q.push(it);
            }
        }
    }

    // Build path
    vector<int> ans;
    int node = t;

    while (parent[node] != node) {
        ans.push_back(node);
        node = parent[node];
    }

    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    return ans;
}

//Problem Link: https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297

/*
Think of it like Google Maps history:
You don't store full route

You just store:
Each location -> previous location

Then reconstruct route later
*/

/*
INPUT
n = 4
edges:
1-2
1-3
2-3
3-4

s = 1
t = 4

GRAPH VIEW
    1
   / \
  2---3
       \
        4

INITIAL STATE
Queue    = [1]
Visited  = [1, 0, 0, 0, 0]
Parent   = [ -, 1, 2, 3, 4 ]
           (each points to itself initially)

Meaning:

We start from node 1
Nobody has been visited yet except 1

STEP 1: PROCESS NODE 1

From 1, neighbors are: 2, 3

We visit them:

Visit 2:

visited[2] = 1
parent[2] = 1   (came from 1)
queue = [2]

Visit 3:
visited[3] = 1
parent[3] = 1   (came from 1)
queue = [2, 3]

STATE NOW
Queue   = [2, 3]

Visited = [1, 1, 1, 0, 0]

Parent:
1 -> 1
2 -> 1
3 -> 1
4 -> 4

STEP 2: PROCESS NODE 2

Neighbors of 2: 1, 3

Both already visited -> nothing changes

Queue = [3]
STEP 3: PROCESS NODE 3

Neighbors: 1, 2, 4

Only 4 is new

Visit 4:
visited[4] = 1
parent[4] = 3   (came from 3)
queue = [4]

STATE NOW
Visited = [1, 1, 1, 1, 1]

Parent:
1 -> 1
2 -> 1
3 -> 1
4 -> 3

STEP 4: PROCESS NODE 4

Neighbors = 3 (already visited)

Queue becomes empty -> BFS ends

FINAL PARENT MAP
2 -> 1
3 -> 1
4 -> 3

Think of it like arrows:

2 -> 1
3 -> 1
4 -> 3

NOW PATH CONSTRUCTION (MOST IMPORTANT PART)

We start from:

t = 4

STEP 1
node = 4
ans = [4]
go to parent[4] = 3

STEP 2
node = 3
ans = [4, 3]
go to parent[3] = 1

STEP 3
node = 1
ans = [4, 3, 1]
stop (since parent[1] = 1)

REVERSE IT
[1, 3, 4]
*/
