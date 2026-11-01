class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn=nums[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i]-mn;
        }
        return ans;
    }
};