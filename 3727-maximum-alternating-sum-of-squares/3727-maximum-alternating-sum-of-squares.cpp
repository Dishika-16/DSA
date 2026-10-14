
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> v;

        for (int x : nums) {
            v.push_back(1LL * x * x);
        }

        sort(v.begin(), v.end());

        int n = v.size();
        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans -= v[i];
        }

        for (int i = n / 2; i < n; i++) {
            ans += v[i];
        }

        return ans;
    }
};
