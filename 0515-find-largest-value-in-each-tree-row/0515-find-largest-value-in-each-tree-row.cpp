
class Solution {
public:
    int levels(TreeNode*root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }
    void nthorder(TreeNode*root , int curr , int level , int &maxi){
        if(root == NULL) return;
        if(curr == level){
            maxi = max(maxi , root->val);
            return;
        }
        nthorder(root->left , curr + 1 , level , maxi);
        nthorder(root->right , curr+1 , level , maxi);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        int n = levels(root);
        for(int i = 1 ; i<=n ; i++){
            int maxi = INT_MIN;
            nthorder(root , 1 , i , maxi);
            ans.push_back(maxi);
        }
        return ans ;
        
        
    }
};