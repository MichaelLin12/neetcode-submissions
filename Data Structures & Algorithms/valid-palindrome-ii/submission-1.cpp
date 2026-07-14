class Solution {
public:
    bool validPalindrome(string s) {
        int fl = 0;
        int fr = s.size() - 1;
        int sl = 0;
        int sr = 0;

        while(fl < fr && s[fl] == s[fr]){
            fl++;
            fr--;
        }

        sl = fl;
        sr = fr;
        fl++;
        sr--;

        bool resa = true;
        while(fl < fr){
            if(s[fl] != s[fr]){
                resa = false;
                break;
            }
            fl++;
            fr--;
        }

        bool resb = true;
        while(sl < sr){
            if(s[sl] != s[sr]){
                resb = false;
                break;
            }
            sl++;
            sr--;
        }

        return resa || resb;
    }
};