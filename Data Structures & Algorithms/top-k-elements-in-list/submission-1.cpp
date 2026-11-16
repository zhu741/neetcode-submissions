class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int, int> table;
        std::vector<int> output;
        for(auto& num:nums){
            table[num]++;
        }

        // build min heap 
        std::priority_queue<std::pair<int,int>, std::vector<pair<int, int>>, std::greater<pair<int,int>>> min_heap;
        for(auto& nodes:table){
            min_heap.push({nodes.second, nodes.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        // copy heap into return vector
        for(int i = 0; i < k; i++){
            output.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return output;
    }
};
