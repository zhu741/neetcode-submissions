class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> output;
        std::set<std::vector<int>> threeSumSet; 
        int size = nums.size();
        for(int i = 0; i < size; i++){
            std::vector<int> sub = nums;
            getSubVector(sub, static_cast<size_t>(i));
            // solve for 2 sum problem
            std::vector<std::vector<int>> twoSumSet = TwoSum(sub, -nums[i]);
            if(twoSumSet.size() == 0){
                continue;
            }else{
                for(auto & ans_entry : twoSumSet){
                    ans_entry.insert(ans_entry.begin(), nums[i]);
                    std::sort(ans_entry.begin(), ans_entry.end());
                    // print_vec(threeSum);
                    threeSumSet.insert(ans_entry);
                }
            }
        }

        return std::vector<std::vector<int>>(threeSumSet.begin(), threeSumSet.end());
    }

    std::vector<std::vector<int>> TwoSum(std::vector<int> & input_vector, int target){
        std::unordered_map<int, int> lookup_table;
        std::vector<std::vector<int>> twoSumSet;
        for(int i = 0; i < input_vector.size(); i++){
            int diff = target - input_vector[i];
            // std::cout<< i << ": diff = " << diff << endl;
            if(lookup_table.find(diff) == lookup_table.end()){
                lookup_table[input_vector[i]]++;
            }else{
                twoSumSet.push_back({input_vector[i],diff}); 
            }
        }
        return twoSumSet;
        
    }

    void getSubVector(std::vector<int> & sub, size_t remove_idx){
        sub.erase(sub.begin()+remove_idx);
    }

    void print_vec(std::vector<int> & nums){
        for(auto & num : nums){
            std::cout << num << ", ";
        }
        std::cout << endl;
    }
    
};
