class Solution{
    private:
        void dfs(int node, vector<int> adj[], int vis[], vector<int> & dfsList){
            vis[node] = 1;
            dfsList.push_back(node);

            for(auto neighbor : adj[node]){
                if(!vis[neighbor]){
                    dfs(neighbor, adj, vis, dfsList);
                }
            }
        }

    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            vector<int> vis(V, 0);
            int start = 0;
            vector<int> dfsList;

            dfs(start, adj, vis, dfsList);

            return dfsList;
        }
};