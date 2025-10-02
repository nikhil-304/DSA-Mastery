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
class BSTIterator {
private:
    stack<TreeNode*> myStack;

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    // Return the next smallest number
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    // Return whether we have a next smallest number
    bool hasNext() {
        return !myStack.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//Problem Link: https://leetcode.com/problems/binary-search-tree-iterator/

/*
Time complexity per next() and hasNext(): O(1)
Space complexity: O(h), where h is the height of the tree (stack stores at most one path from root to leaf)
*/
