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
    void helper(TreeNode* root, vector<int> &vals){
        if(root == NULL) return;

        helper(root->left, vals);  //1.) Recur on left child
        vals.push_back(root->val); //2.) Visit root node
        helper(root->right, vals); //3.) Recur on right child
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Inorder Traversal: left->root->right
        vector<int> inOrderVals;
        helper(root, inOrderVals);
        return inOrderVals;
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/binary-tree-inorder-traversal/
Code360: https://www.naukri.com/code360/problems/inorder-traversal_3839605
*/

/*
Time Complexity: O(n)
Space Complexity: O(n) -- Recursive Stack Space
*/
