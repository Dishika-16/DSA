
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        long long odd = 0;
        long long even = 1;
        long long count = 0;

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum % 2 != 0) {
                count += even;
                odd++;
            }
            else {
                count += odd;
                even++;
            }

            count %= 1000000007;
        }

        return count;
    }
};