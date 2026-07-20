class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // we should in place sort them
        // to have non-duplicates
        // then we run a two-pointer from
        // front and back to get the solution
        // and achieve the space
        // we don't even need to remove duplicates!!!

        int lo = 0;
        int hi = numbers.size() - 1;
        while(lo < hi){
            if(numbers[lo]+numbers[hi] < target){
                lo++;
            }else if(numbers[lo] + numbers[hi] > target){
                hi--;
            }else{
                return std::vector<int>{++lo,++hi};
            }
        }

        return std::vector<int>{};
    }
};
