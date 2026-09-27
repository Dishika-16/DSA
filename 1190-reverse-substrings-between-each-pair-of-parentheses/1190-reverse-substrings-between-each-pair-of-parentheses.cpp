class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] != ')') {
                st.push(s[i]);
            }
            else {
                string temp = "";

                while(!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // remove '('
                st.pop();

                // put reversed part back
                for(char ch : temp) {
                    st.push(ch);
                }
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};