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
    int height(TreeNode* node, int &diameter){
        if(node == NULL) return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh+rh);
        return max(lh, rh) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/diameter-of-binary-tree/description/
Code360: https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552
*/

/*
Time Complexity: O(n)
Space Complexity: O(n) --- Auxiliary Stack Space
*/
