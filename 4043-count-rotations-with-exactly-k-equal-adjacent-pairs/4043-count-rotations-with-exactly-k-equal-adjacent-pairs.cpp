class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int ans = 0;

        // Try every rotation
        for (int r = 0; r < n; r++) {

            // Create rotated string
            string t = s.substr(r) + s.substr(0, r);

            int count = 0;

            // Count equal adjacent pairs
            for (int i = 0; i < n - 1; i++) {
                if (t[i] == t[i + 1]) {
                    count++;
                }
            }

            // Check score
            if (count == k) {
                ans++;
            }
        }

        return ans;
    }
};