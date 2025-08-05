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
    // Helper function that returns height if balanced, else -1
    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;  // left subtree not balanced

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;  // right subtree not balanced

        if (abs(leftHeight - rightHeight) > 1) return -1; // current node not balanced

        return max(leftHeight, rightHeight) + 1; // height of this node
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1 ? true : false;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/balanced-binary-tree/
Code360: https://www.naukri.com/code360/problems/is-height-balanced-binary-tree_975497
https://www.naukri.com/code360/problems/balanced-binary-tree_1799468
*/

/*
Time Complexity: O(n)
Space Complexity: O(n)  --- Auxiliary Recursive Stack Space
*/

