class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        
        std::vector<std::vector<int>> res{};
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = 0 - nums[i];
            int lo = i + 1;
            int hi = nums.size() - 1;
            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    res.push_back({nums[lo],nums[hi],nums[i]});
                    hi--;
                    while(hi >= 0 && nums[hi] == nums[hi+1]){
                        hi--;
                    }
                    lo++;
                    while(lo < nums.size() && nums[lo] == nums[lo-1]){
                        lo++;
                    }
                }else if(nums[lo] + nums[hi] < target){
                    lo++;
                    while(lo < nums.size() && nums[lo] == nums[lo - 1]){
                        lo++;
                    }
                }else{
                    hi--;
                    while(hi >= 0 && nums[hi] == nums[hi+1]){
                        hi--;
                    }
                }
            }
        }

        return res;
    }
};
