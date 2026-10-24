class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        stack<int> st;

        for(int i = 0; i < nums.size(); i++) {
            st.push(nums[i]);
        }

        int ans = st.top();
        st.pop();

        while(!st.empty()) {
            int curr = st.top();

            if(abs(curr) < abs(ans)) {
                ans = curr;
            }
            else if(abs(curr) == abs(ans) && curr > ans) {
                ans = curr;
            }

            st.pop();
        }

        return ans;
    }
};