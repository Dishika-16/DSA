class Solution {
public:

    int levels(TreeNode* root) {
        if(root == NULL) return 0;

        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthlevel(TreeNode* root, int level, int curr, vector<int>& ans) {

        if(root == NULL) return;

        if(curr == level) {
            ans[level] = root->val;
            return;
        }

        nthlevel(root->left, level, curr + 1, ans);
        nthlevel(root->right, level, curr + 1, ans);
    }

    void levelOrder(TreeNode* root, vector<int>& ans) {

        int n = ans.size();

        for(int i = 0; i < n; i++) {
            nthlevel(root, i, 0, ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans(levels(root), 0);

        levelOrder(root, ans);

        return ans;
    }
};