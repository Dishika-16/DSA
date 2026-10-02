class Solution {
public:

    void helper(int n, int open, int close, string s,
                stack<char> st, vector<string>& ans) {

        // Complete string
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add '('
        if (open < n) {
            stack<char> temp = st;
            temp.push('(');

            helper(n, open + 1, close, s + "(", temp, ans);
        }

        // Add ')'
        if (close < open && !st.empty()) {
            stack<char> temp = st;
            temp.pop();

            helper(n, open, close + 1, s + ")", temp, ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        stack<char> st;

        helper(n, 0, 0, "", st, ans);

        return ans;
    }
};