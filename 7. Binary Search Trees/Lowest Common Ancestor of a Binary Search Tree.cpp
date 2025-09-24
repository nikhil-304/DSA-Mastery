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
        if(root == NULL) return NULL;

        int curr = root->val;

        if(curr < p->val && curr < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Code360: https://www.naukri.com/code360/problems/lca-in-a-bst_981280
*/

/*
Time Complexity: O(height) (O(n) in the worst case, O(log n) in the best case)
Space Complexity: O(h) (O(n) in the worst case, O(log n) in the best case)
*/

/*
Approach to find LCA in a Binary Search Tree (BST):
1. Start from the root of the tree.
2. Compare the values of the current node with the values of p and q.
    - If both p and q are smaller than the current node, LCA lies in the left subtree.
    - If both p and q are larger than the current node, LCA lies in the right subtree.
    - If one node is smaller and the other is larger (or one of them is equal to the current node),
      the current node is the LCA.
3. Continue the process until you find the LCA node.
*/
