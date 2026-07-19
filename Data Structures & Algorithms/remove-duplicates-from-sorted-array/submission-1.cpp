class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // just move the duplicates to the back of the
        //array
        // its sorted dumbass
        int i = 1;
        int k = 1;
        int last = 1;
        while(i < nums.size()){
            while(i < nums.size() && nums[i] == nums[i-1]){
                i++;
            }
            if(i == nums.size()){
                break;
            }
            nums[last] = nums[i];
            last++;
            k++;
            i++;
        }

        return k;   
    }
};