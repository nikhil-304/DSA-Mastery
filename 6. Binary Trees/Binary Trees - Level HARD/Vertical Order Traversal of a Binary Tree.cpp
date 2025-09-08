/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            
            nodes[x][y].insert(node->val);
            if(node->left != NULL) todo.push({node->left, {x-1, y+1}});
            if(node->right != NULL) todo.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> ans;

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

//Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
Time Complexity: O(Nlog?N)
Space Complexity: O(N)
*/

/*

(vertical, level)
        node
        /  \
(-1, +1)   (+1, +1)
  left       right

(vertical, level, That_Level_ke_Vertical_Set_values)
map<int, map<int, multiset<int>>> nodes;
map<vertical, map<level, LevelValsSet>> nodes;

(node, vertical, level)
queue<pair<TreeNode*, pair<int, int>>> todo;
queue<pair<node*, pair<vertical, level>>> todo;
*/
