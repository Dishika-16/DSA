class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            string ans = "";
            for(int i = 0 ; i<s.length() ; i = i+k){
                int sum = 0;
                for(int j = i ; j<i+k && j<s.length(); j++){
                    sum = sum + (s[j] - '0');
                }
                ans = ans + to_string(sum);
            
            }
            s = ans;
        }
        return s ;
        
    }
};