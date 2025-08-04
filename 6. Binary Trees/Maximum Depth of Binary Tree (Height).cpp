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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + (max(lh, rh));
    }
};

/*
Problem Link: 
LeetCode: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Code360: https://www.naukri.com/code360/problems/maximum-depth-of-a-binary-tree_1090542
*/

/*
Time complexity: O(N)
Space complexity: O(H), where H is the height of the tree, and in the worst case, H=O(N).
*/
