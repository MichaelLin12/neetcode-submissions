class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        A common inefficiency is to start counting a 
        sequence from every number in the array, 
        which leads to O(n^2) time complexity. 
        The key optimization is to only start 
        counting from numbers that are the beginning 
        of a sequence (i.e., num - 1 is not in the set).
        */
       std::unordered_map<int,int> seq{};
       std::vector<bool>flags(nums.size(),false); // doesn't work
       int res = 0;

       for(auto& x: nums){
            seq[x] = x - 1;
       }



       for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            int n = nums[i];
            if(seq.count(n+1)){
                continue;
            }
            while(seq.count(n)){
                temp++;
                n = seq[n];

            }

            res = std::max(temp,res);
       }

       return res;
    }
};
