class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.length();

        for(int i = 0; i < n; i++) {

            if(path[i] == '/') {
                continue;
            }

            string temp = "";

            while(i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if(temp == ".") {
                continue;
            }
            else if(temp == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(temp);
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans == "")
            return "/";

        return ans;
    }
};