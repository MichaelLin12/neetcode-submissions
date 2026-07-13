class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // well if you put it in a hashmap it can work ...
        // but it uses O(N) space

        // we could go through and find the min that
        // is still positive but that gets close to
        // but not so a solution

        // sorting would be O(NlogN) or use too much space
        std::vector<bool> arr(nums.size()+1,false);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i] < nums.size() + 1){
                arr[nums[i]] = true;
            }
        }

        for(int i = 1; i < arr.size(); i++){
            if(!arr[i]){
                return i;
            }
        }

        return nums.size() + 1;
    }
};