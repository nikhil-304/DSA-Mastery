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
    int maxPathDown(TreeNode* node, int &maxi){
        if(node == NULL) return 0;

        int leftSum = max(0, maxPathDown(node->left, maxi));
        int rightSum = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, (leftSum + rightSum + node->val));

        return max(leftSum, rightSum) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Code360: https://www.naukri.com/code360/problems/binary-tree-maximum-path-sum_1280142
*/

/*
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree (can be O(n) in the worst case).
*/
