class Solution {
public:
    //Iterative Approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrderVals;

        if(root == NULL) return inOrderVals;

        stack<TreeNode*> st;

        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }

            TreeNode* current = st.top();
            st.pop();

            inOrderVals.push_back(current->val);

            root = current->right;
        }
        return inOrderVals;
    }
};

//Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
