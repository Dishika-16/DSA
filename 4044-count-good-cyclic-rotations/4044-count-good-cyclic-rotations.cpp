class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long total = 0;

        // Total sum of the array
        for (int x : nums) {
            total += x;
        }

        // Sum of first half
        long long window = 0;

        for (int i = 0; i < half; i++) {
            window += nums[i];
        }

        int ans = 0;

        // Check every rotation
        for (int i = 0; i < n; i++) {

            // First half > second half
            // second half = total - window
            if (window > total - window) {
                ans++;
            }

            // Move window by one position
            window -= nums[i];

            window += nums[(i + half) % n];
        }

        return ans;
    }
};