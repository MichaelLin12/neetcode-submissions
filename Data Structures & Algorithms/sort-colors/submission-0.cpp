class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        One way is to use counting sort.
        but that is not a one pass algorithm that uses
        constant extra space. So while it does resolve
        the problem, it does not solve the followup.
        */

        std::vector<int> count(3,0);
        std::vector<int> output(nums.size(),0);

        for(auto& ele: nums){
            ++count[ele];
        }

        for(int i = 1; i < count.size(); i++){
            count[i] += count[i-1];
        }

        for(int i = nums.size() - 1; i >= 0; --i){
            output[count[nums[i]]-1] = nums[i];
            --count[nums[i]];
        }

        nums = output;
    }
};