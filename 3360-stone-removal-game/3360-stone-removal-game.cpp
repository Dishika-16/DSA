
class Solution {
public:
    bool canAliceWin(int n) {
        int a = 10;
        bool alice = true;

        while(n >= a) {
            n=n-a;
            a--;
            alice = !alice;
        }

        return !alice;
    }
};