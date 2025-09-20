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
    void helper(TreeNode* root, int k, int &cnt, int &kthSmallVal){ 
        //Inorder Traversal
        if(root == NULL) return;

        helper(root->left, k, cnt, kthSmallVal);  //1.) Recur on left child
        cnt++;
        if(cnt == k){
            kthSmallVal = root->val;
            return;
        }
        helper(root->right, k, cnt, kthSmallVal); //3.) Recur on right child
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int kthSmallVal = -1;
        helper(root, k, cnt, kthSmallVal);
        return kthSmallVal;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Code360: https://www.naukri.com/code360/problems/kth-smallest-node-in-bst_920441
*/

/*
Inorder Traversal has a property of traversing elements in a sorted order as it's a BST
left < Node < right
*/

/*
Time Complexity: O(n)
Space Complexity: O(h) (worst case: O(n), best case: O(log n))  --Recursive Stack Space
*/
