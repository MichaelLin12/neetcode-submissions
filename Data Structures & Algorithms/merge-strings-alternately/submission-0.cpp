class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0;
        int r = 0;
        std::string res{};
        while(l < word1.size() && r < word2.size()){
            res += word1[l];
            res += word2[r];
            l++;
            r++;
        }

        if(l < word1.size()){
            res += word1.substr(l, word1.size() - l);
        }

        if(r < word2.size()){
            res += word2.substr(r, word2.size() - r);
        }

        return res;
    }
};