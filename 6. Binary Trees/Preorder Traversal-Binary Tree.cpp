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
private:
    void helper(TreeNode* node, vector<int>& vals) {
        if (node == nullptr) return;

        vals.push_back(node->val);  // 1.) Visit root
        helper(node->left, vals);   // 2.) Recur on left child
        helper(node->right, vals);  // 3.) Recur on right child
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        // PreOrder Traversal: root->left->right
        vector<int> preOrderVals;
        helper(root, preOrderVals);
        return preOrderVals;
    }
};

/*
Problem Link: 
Leetcode: https://leetcode.com/problems/binary-tree-preorder-traversal/
Code360: https://www.naukri.com/code360/problems/preorder-binary-tree_5948
*/

/*
Time Complexity: O(n)
Space Complexity: O(n) -- Recursive Stack Space
*/
