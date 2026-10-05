class Solution {
public:
    bool sameTree(TreeNode* root) {
        if(root == NULL) return true;

        if(root->left != NULL && root->val != root->left->val)
            return false;

        if(root->right != NULL && root->val != root->right->val)
            return false;

        return sameTree(root->left) &&
               sameTree(root->right);
    }

    bool isUnivalTree(TreeNode* root) {
        return sameTree(root);
    }
};