class Solution {
public:
    int helper(TreeNode* root, bool isleft) {
        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL) {
            if(isleft)
                return root->val;
            else
                return 0;
        }

        int leftsum = helper(root->left, true);
        int rightsum = helper(root->right, false);

        return leftsum + rightsum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};