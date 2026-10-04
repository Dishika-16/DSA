class Solution {
public:
    bool sameTree(TreeNode* root, TreeNode* subroot) {
        
        if(root == NULL && subroot == NULL){
            return true;
        }

        if(root == NULL || subroot == NULL){
            return false;
        }

        if(root->val != subroot->val){
            return false;
        }

        return sameTree(root->left, subroot->left) &&
               sameTree(root->right, subroot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL){
            return false;
        }

        if(sameTree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};