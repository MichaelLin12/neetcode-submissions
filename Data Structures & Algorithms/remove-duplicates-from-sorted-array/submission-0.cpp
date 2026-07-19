class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // just move the duplicates to the back of the
        //array
        std::unordered_set<int> dups{};
        int i = 0;
        int k = 0;
        while(i < nums.size()){
            if(!dups.count(nums[i])){
                dups.insert(nums[i]);
                std::swap(nums[k],nums[i]);
                k++;
                i++;
            }else{
                i++;
            }
        }

        return k;   
    }
};