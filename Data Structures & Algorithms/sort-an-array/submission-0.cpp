class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // quicksort
        return sortArray(nums,0,nums.size()-1);
    }

    vector<int> sortArray(vector<int>& nums, int start, int end){
        if(start >= end){
            return nums;
        }

        int pivot = nums[end];
        int i = start - 1;
        for(int j = start; j < end; j++){
            if(nums[j] <= pivot){
                std::swap(nums[++i], nums[j]); 
            }
        }

        std::swap(nums[++i],nums[end]);
        sortArray(nums,start, i-1);
        sortArray(nums,i+1,end);

        return nums;
    }
};