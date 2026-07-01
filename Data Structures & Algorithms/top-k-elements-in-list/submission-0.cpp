class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Use a map and track the top k frequent
        // run it through linearly ... or
        // go through the trouble of building a heap??
        // or just have the key, value pair in the heap
        // or just do sorting I guess

        std::vector<std::pair<int,int>> heap{static_cast<std::size_t>(k),std::make_pair(0,0)};
        std::make_heap(heap.begin(), heap.end());
        

        std::unordered_map<int,int> count{};
        for(auto& num: nums){
            count[num]++;
        }

        for(auto [key, value]: count){
            if(heap.size() >= k && heap[0].first > -1* value){
                std::pop_heap(heap.begin(), heap.end());
                heap.pop_back();
            }

            if(heap.size() < k){
                heap.emplace_back(-1*value, key);
                std::push_heap(heap.begin(), heap.end());
            }
        }

        std::vector<int> res{};
        for(auto& [key, value]: heap){
            res.push_back(value);
        }
        return res;
    }
};