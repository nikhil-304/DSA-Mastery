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
    //Helper function to handle deletion of key and merging of tree consistently
    //Func desinged to merge the del node's right to the del node's left of last right  element
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;

        return root->left;
    }

    //Helper function to find out the leftmost subtree's last right element
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //Edge Cases
        //If tree is empty, return empty tree
        if(root == NULL) return root;
        //If the key is the first element only i.e. root
        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root != NULL){
            //Left subtree
            if(root->val > key){
                //If left exists and it's the key
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                //If key not found, move to left
                else{
                    root = root->left;
                }
            }
            //Right Subtree
            else{
                //If right exists and it's the key
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                //If key not found, move to right
                else{
                    root = root->right;
                }
            }
        }

        //return the head of the tree
        return dummy;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/delete-node-in-a-bst/
Code360: https://www.naukri.com/code360/problems/delete-node-in-bst_920381
*/

/*
Time Complexity: O(height of tree)
Space Complexity: O(1)
*/
