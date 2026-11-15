class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> table;    // num: occurance count
        std::vector<int> output;
        
        for(int& num:nums){
            if(table.find(num) == table.end()){
                table[num] = 1; 
            }else{
                table[num]++;
            }
        }

        std::vector<std::pair<int, int>> table_vec = {table.begin(), table.end()};
        std::sort(table_vec.begin(), table_vec.end(), [](const auto& a, const auto& b){
            return a.second > b.second; 
        });

        for(int i = 0; i < k; i++){
            output.push_back(table_vec[i].first);
        }

        return output;
        
    }
};
