class Solution {
public:
    bool validDigit(int n, int x) {
        bool hasX = false;
        while(n>9){
            int rem = n % 10;
            if(rem == x){
                hasX = true;
            }
            n = n / 10;
        }
        return hasX && (n != x);
    }
};