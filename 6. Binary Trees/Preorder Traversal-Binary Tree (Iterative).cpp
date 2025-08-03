class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrderVals;
        if (root == nullptr) return preOrderVals;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();

            // Visit the node (process root)
            preOrderVals.push_back(current->val);

            // Push right first so left is processed first
            if (current->right) st.push(current->right);
            if (current->left) st.push(current->left);
        }

        return preOrderVals;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
