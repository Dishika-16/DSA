class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            int diff=mx-nums[i];
            count=count+diff;

        }
        return count;
        
    }
};