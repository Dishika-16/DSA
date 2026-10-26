class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        for(int i = 0 ; i<nums.size() ; i++){
            st.insert(nums[i]);

        }
        stack<int>s;
        for(int it : st){
            s.push(it);
        }
        if(s.size() < 3 ){
            return s.top();
        }
        s.pop();
        s.pop();

        return s.top();
    }
};