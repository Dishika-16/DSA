class Solution {
public:
    string decodeString(string s) {

        stack<int> nums;
        stack<string> st;

        string curr = "";
        int num = 0;

        for(int i = 0; i < s.length(); i++) {

            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {
                nums.push(num);
                st.push(curr);

                num = 0;
                curr = "";
            }

            else if(s[i] == ']') {

                int n = nums.top();
                nums.pop();

                string temp = st.top();
                st.pop();

                for(int j = 0; j < n; j++) {
                    temp += curr;
                }

                curr = temp;
            }

            else {
                curr += s[i];
            }
        }

        return curr;
    }
};