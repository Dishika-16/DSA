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
public:
    int prev = INT_MIN;
    int count = 0;
    int maxi= 0;
    vector<int>ans;
    bool first = true;
    void isBST(TreeNode*root){
        if(root == NULL) return;
        isBST(root->left);
        isDuplicate(root->val);
        isBST(root->right);
    }
    void isDuplicate(int val){
        if(first || val!= prev ){
            count = 1;
            first = false;
        }
        else{
            count++;
        }
        if(count>maxi){
            maxi = count;
            ans.clear();
            ans.push_back(val);
        }
        else if (count == maxi){
            ans.push_back(val);
        }
        prev = val;
    }
    vector<int> findMode(TreeNode* root) {
        isBST(root);
        return ans;
    }
};