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
class BSTIterator{
private:
    stack<TreeNode*> myStack;
    //reverse -> true -> before
    //reverse -> false -> next
    bool reverse = false;

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);

        return tmpNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
Code360: https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631
*/

/*
Time Complexity: O(n)
Space Complexity: O(h)*2 -> left and right into stack
*/

/*
Refer Binary Search Tree Iterator Problem
As an Inorder traversal gives the final result as a sorted result, we'll use this as our advantage
Normal BSTIterator pushes the left subtree into the stack
Reversed BSTIterator pushes the right subtree into the stack
Normal LEFT BSTIterator will give the smallest value, as it's the start of inorder
i.e. it'll be 2
Reversed RIGHT BSTIterator will give the largest value, as it's the end of inorder
i.e. it'll be 7
target = k = 9
2+9 = 9 == true
*/
