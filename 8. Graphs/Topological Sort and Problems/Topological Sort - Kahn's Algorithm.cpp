class Solution
{
    vector<int> topSort(int n, vector<vector<int>> &adj){
        vector<int> indegree(n, 0); // stores number of incoming edges for each node
        
        // compute indegree of each node
        for(int i=0 ; i<n ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        // push all nodes with indegree 0 (no dependencies)
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo; // stores the topological order
        
        // BFS (Kahn's Algorithm)
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); // add current node to result
            
            // reduce indegree of neighbors
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it); // if no more dependencies, add to queue
            }
        }
        
        return topo; // return topological ordering
    }
};

//Problem Link: https://www.naukri.com/code360/problems/topological-sort_982938

/*
Kahn's Algorithm is used for performing topological sorting on a Directed Acyclic Graph (DAG).

Topological sorting provides a linear ordering of vertices such that for every directed edge from a node U to a node V, node U appears before V in the ordering.

Key concepts behind the algorithm:

- Directed Acyclic Graph (DAG): This algorithm only works on graphs that are directed and do not contain cycles. If a graph has a cycle, a valid linear ordering cannot exist because of the circular dependencies.
- In-degree: The algorithm relies on the in-degree, which is the count of incoming edges to a node.
    BFS Approach: Kahn's algorithm utilizes a Breadth-First Search (BFS) strategyby:
    1. Identifying nodes with an in-degree of 0 (meaning they have no dependencies) and adding them to a queue.
    
    2. Processing each node from the queue, adding it to the topological sort, and effectively "removing" its outgoing edges.
    
    3. Reducing the in-degree of the adjacent nodes; if any of those nodes reach an in-degree of 0, they are added to the queue.

This process continues until all nodes have been included in the ordering
*/

/*
   (5)        (4)
    | \      / |
    v  v    v  v
   (2)   (0)  (1)
    \          ^
      v  (3) /
   
This graph contains nodes 0 to 5. Here is the Adjacency List representation:
    0: []
    1: []
    2: [3]
    3: [1]
    4: [0, 1]
    5: [0, 2]

Dry Run Process

1. Initialization: First, we calculate the in-degree (incoming edges) for every node:
    0: 2 (from 4 and 5)
    1: 2 (from 4 and 3)
    2: 1 (from 5)
    3: 1 (from 2)
    4: 0
    5: 0
Queue status: We add all nodes with in-degree 0 to the queue: [4, 5].

2. Processing the Queue:
    - Pop 4: Add 4 to our topological order. Since 4 points to 0 and 1, we decrement their in-degrees.
    In-degree of 0 becomes 1.
    In-degree of 1 becomes 1.

    - Pop 5: Add 5 to our order. Since 5 points to 0 and 2, decrement their in-degrees.
    In-degree of 0 becomes 0. Queue: [0].
    In-degree of 2 becomes 0. Queue: [0, 2].

    - Pop 0: Add 0 to order. It has no outgoing edges, so nothing happens.

    - Pop 2: Add 2 to order. It points to 3, decrement 3's in-degree.
    In-degree of 3 becomes 0. Queue: [3].

    - Pop 3: Add 3 to order. It points to 1, decrement 1's in-degree.
    In-degree of 1 becomes 0. Queue: [1].

    - Pop 1: Add 1 to order.
    
Final Result: The valid linear ordering produced is [4, 5, 0, 2, 3, 1].
*/
