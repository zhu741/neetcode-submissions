class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> table_s;
        std::unordered_map<char, int> table_t;
        for(auto & s_char : s){
            table_s[s_char]++;
        }
        for(auto & t_char : t){
            table_t[t_char]++;
        }

        return table_s == table_t;
    }
};
