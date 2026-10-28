
class Solution {
public:
    int count(TreeNode*root){
        if(root == NULL) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    bool check(TreeNode*root , int index , int total){
        if(root == NULL) return true;
        if(index>=total) return false ;
        return check(root->left , 2*index+1 , total)&& check(root->right , 2*index +2,total);
    }
    bool isCompleteTree(TreeNode* root) {
        int total = count(root);
        return check(root , 0 , total);
    }
};