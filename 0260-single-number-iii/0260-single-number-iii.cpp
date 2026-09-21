class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        stack<int> st;

        for(int i = 0; i < n; i++) {

            if(!st.empty() && nums[i] == st.top()) {
                st.pop();
            }
            else {
                st.push(nums[i]);
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
    
};