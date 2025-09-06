class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                // if this is the last node of this level
                if(i == size - 1) {
                    result.push_back(node->val);
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return result;
    }
};

//Problem Link: https://leetcode.com/problems/binary-tree-right-side-view/

/*
Time Complexity = O(N)
Space Complexity = O(N)
*/
