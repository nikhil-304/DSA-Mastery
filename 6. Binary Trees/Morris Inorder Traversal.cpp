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
    //Morris Inorder Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrderVals;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                inOrderVals.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inOrderVals.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inOrderVals;
    }
};

//Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)  -- No recursive stack space nor simple stack space
*/
