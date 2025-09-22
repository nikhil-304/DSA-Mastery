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
    bool isBTorBST(TreeNode* root, long long min, long long max){
        if(root == NULL) return true;

        if(root->val <= min || root->val >= max) return false;
        return isBTorBST(root->left, min, root->val) && isBTorBST(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBTorBST(root, LLONG_MIN, LLONG_MAX);
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/validate-binary-search-tree/
Code360: https://www.naukri.com/code360/problems/validate-bst_981275
*/

/*
Time Complexity: O(n)
Space Complexity: O(n)  -- Recursive Stack Space
*/

/*
For this problem to solve, we'll use a range to check that if this node falls in this range. Left child range: (min, node->val)
Right child range: (node->val, max)

range = [INT_MIN, INT_MAX]

          13
        /    \
      10      15
     /  \    /  \
    7   12  14  17
     \         /
      9       16
    /
   8

Start: 13 (min=-8, max=+8)
    ? valid ? go left first ? 10 (min=-8, max=13)
        ? valid ? go left ? 7 (min=-8, max=10)
            ? valid ? go left ? NULL ? true
            then go right ? 9 (min=7, max=10)
                ? valid ? go left ? 8 (min=7, max=9)
                    ? valid ? left NULL, right NULL
                right NULL
        then back to 10 ? go right ? 12 (min=10, max=13) ? ? valid ? children NULL
then back to 13 ? go right ? 15 (min=13, max=+8)
    ? valid ? left ? 14 (min=13, max=15) ? ? valid ? children NULL
    then right ? 17 (min=15, max=+8)
        ? valid ? left ? 16 (min=15, max=17) ? ? valid ? children NULL
        right NULL  

AND SO ON...

Egde Case why use LLONG instead of INT_MIN/MAX
INT_MAX ? 2,147,483,647 (˜ 2.1 billion)
LLONG_MAX ? 9,223,372,036,854,775,807 (˜ 9 quintillion)
So yes — LLONG_MAX is way bigger than INT_MAX.

If max = INT_MAX, then root->val = 2147483647 equals max ? false BST.
If max = LLONG_MAX, then root->val = 2147483647 is much smaller than 9,223... ? true BST.
*/
