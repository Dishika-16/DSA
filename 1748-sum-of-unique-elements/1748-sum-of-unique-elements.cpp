class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }

            if(count == 1) {
                st.push(nums[i]);
            }
        }

        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};