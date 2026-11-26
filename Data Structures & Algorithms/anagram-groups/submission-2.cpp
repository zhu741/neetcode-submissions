class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for(int i = 0; i < strs.size(); i++){
            std::string key = make_key(strs[i]);
            groups[key].push_back(strs[i]);
        }

        return convert(groups);
    }

    std::string make_key(std::string input){
        std::vector<int> count(26, 0);
        std::string key = "";
        for(const char & c:input){
            count[c-'a']++;
        }

        for(int & element:count){
            key += std::to_string(element);
            key.push_back(',');
        }
        return key;
    }

    std::vector<std::vector<std::string>> convert(std::unordered_map<std::string, std::vector<std::string>> & input){
        std::vector<std::vector<std::string>> output;
        for(const auto & [key, group]:input){
            output.push_back(group);
        }
        return output;
    }
};
