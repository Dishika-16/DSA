class Solution {
public:
    string reverseByType(string s) {
        stack<int>letters;
        stack<int>special;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i]>='a' && s[i]<='z'){
                letters.push(s[i]);
            }
            else{
                special.push(s[i]);
            }
        }
        for(int i = 0 ; i<s.length(); i++){
            if(s[i]>= 'a' && s[i] <= 'z'){
                s[i] = letters.top();
                letters.pop();
            }
            else{
                s[i] = special.top();
                special.pop();
            }
            
        }
        return s;
    }
};