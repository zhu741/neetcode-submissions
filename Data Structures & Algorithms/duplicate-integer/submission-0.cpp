class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> lookup_table;
        bool output = false;
        for(auto& num:nums){
            if(lookup_table.find(num) == lookup_table.end()){
                lookup_table.insert({num, 1});
            }else{
                output = true;
            }
        }
        return output;
    }
};