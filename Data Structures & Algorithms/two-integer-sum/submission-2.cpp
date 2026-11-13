class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table{};
        int first_index, second_index; 
        int diff; 
        for(int i = 0; i < nums.size(); i++){
            diff = target - nums[i];
            // don't find it -> table it
            if(table.find(diff) == table.end()){
                table[nums[i]] = i;
            }else{
                first_index = (table[diff] > i) ? i : table[diff];
                second_index = (table[diff] > i) ? table[diff] : i;
                return {first_index, second_index};
            }
        }

        return {};
    }
};
