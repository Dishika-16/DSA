class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        
        sort(nums.begin() , nums.end());
        int maxd = 0;
        for(int i = 1 ; i < n ; i++){
            int diff = nums[i] - nums[i-1];
            if(diff>maxd){
                maxd = diff;
            }
        }
        return maxd;
    }
};

