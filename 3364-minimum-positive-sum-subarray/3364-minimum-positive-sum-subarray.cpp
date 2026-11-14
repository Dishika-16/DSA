
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = INT_MAX;

        int diff = r - l;

        for(int x = 0; x <= diff; x++) {

            int len = l + x;

            for(int i = 0; i + len <= n; i++) {

                int sum = 0;

                for(int j = i; j < i + len; j++) {
                    sum += nums[j];
                }

                if(sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
