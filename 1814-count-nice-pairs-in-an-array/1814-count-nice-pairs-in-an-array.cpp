class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n>0){
            r = r*10;
            r = r+n%10;
            n = n/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        map<int,int>mp;
        for(int i = 0 ; i<n ;i++){
            int val = nums[i]-rev(nums[i]);
            mp[val]++;
        }
    
        long long count = 0;
        int mod = 1e9 + 7;

        for(auto it : mp) {

            long long freq = it.second;

            
            long long pairs = (freq * (freq - 1)) / 2;

            count = (count + pairs) % mod;
        }

        return count;
    }
};