/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1. Base condition
        if(root == NULL || root == p || root == q){
            return root;
        }

        // 2. Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 3. Decision making
        if(left == NULL) return right;  // both are in right side
        else if(right == NULL) return left;  // both are in left side
        else return root;  // one found on left, one found on right ? this is LCA
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Code360: https://www.naukri.com/code360/problems/lca-in-a-bst_981280
*/

/*
Time Complexity: O(N)
Space Complexity: O(N) -- Recursive Stack Space
*/
