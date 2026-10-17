
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;
        unordered_map<int, int> index;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
            index[nums[i]] = i;
        }

        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            int x = digitSum(a.first);
            int y = digitSum(b.first);

            if (x == y) return a.first < b.first;
            return x < y;
        });

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == arr[i].first)
                continue;

            int j = index[arr[i].first];

            index[nums[i]] = j;
            index[arr[i].first] = i;

            swap(nums[i], nums[j]);
            swaps++;
        }

        return swaps;
    }
};
