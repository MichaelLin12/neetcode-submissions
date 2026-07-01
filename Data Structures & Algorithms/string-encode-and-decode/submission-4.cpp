class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res{};
        for(auto& str: strs){
            res += std::to_string(str.size());
            res += "#";
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        int j = 0;
        std::vector<std::string> res{};
        while(j < s.size()){
            int size = 0;
            while(j < s.size()){
                if(s[j] == '#'){
                    std::cout << s.substr(i,j-i) << std::endl;
                    size = std::stoi(s.substr(i,j-i));
                    break;
                }
                j++;
            }
            std::string sub = s.substr(j+1,size);
            res.push_back(sub);
            j += size+1;
            i = j;
        }

        return res;
    }
};
