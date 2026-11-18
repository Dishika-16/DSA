class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        if(n%2 !=0) return 0;
        int count = 0;
        for(int i = 0 ; i<n ; i = i+2){
            if(s[i]!=s[i+1]){
                count++;
            }
        }
        return count;
    }
};