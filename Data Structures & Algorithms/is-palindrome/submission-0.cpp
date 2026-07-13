class Solution {
public:
    bool isPalindrome(string s) {
        std::string k = "";
        for(int x = 0; x < s.size(); x++){
            if(s[x] != ' '){
                k += std::tolower(s[x]);
            }
        }
        std::cout << k << std::endl;
        int i = 0;
        int j = k.size() - 1;
        while(i < j){
            if(!std::isalnum(k[i])){
                i++;
                continue;
            }else if(!std::isalnum(k[j])){
                j--;
                continue;
            }
            if(k[i] != k[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
