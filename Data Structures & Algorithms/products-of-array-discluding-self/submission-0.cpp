class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(),0);
        std::vector<int> suffix(nums.size(),0);

        int i = 0;
        int j = nums.size() - 1;
        prefix[i] = 1;
        suffix[j] = 1;
        i++;
        j--;
        while(i < nums.size() && j >= 0){
            prefix[i] = nums[i-1]*prefix[i-1];
            suffix[j] = nums[j+1]*suffix[j+1];
            j--;
            i++;
        }

        std::vector<int> res(nums.size(),0);
        for(int x = 0; x < nums.size(); x++){
            res[x] = prefix[x]*suffix[x];
        }

        return res;
    }
};
