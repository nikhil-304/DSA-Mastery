class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[node] = 1;

        for (auto neighbor : adjList[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adjList, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adjList(n);

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjList, vis);
            }
        }

        return cnt;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/number-of-provinces/
Code360: https://www.naukri.com/code360/problems/find-the-number-of-states_1377943
*/

/*
Building Adjacency List: O(n×n)=O(n^2)
DFS Traversal: O(V+E)

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

/*
| Approach              | Time  | Space |
| --------------------- | ----- | ----- |
| DFS on Matrix         | O(n²) | O(n)  |
| DFS on Adjacency List | O(n²) | O(n²) |
*/

/*
####### No Adjacency List Conversion Algorithm ############

class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, isConnected, vis);
            }
        }

        return cnt;
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n)
*/