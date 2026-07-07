class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       std::unordered_map<int,int> seq{};
       std::vector<bool>flags(nums.size(),false);
       int res = 0;

       for(auto& x: nums){
            seq[x] = x - 1;
       }



       for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            int n = nums[i];
            while(seq.count(n)){
                temp++;
                n = seq[n];
            }

            res = std::max(temp,res);
       }

       return res;
    }
};
