class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        int ans = nums[mid];

        map<int , int>mp;
        for(auto x : nums){
            mp[x]++;
        }      
        if(mp[ans] == 1){
            return true;
        }
        return false;
    }
};