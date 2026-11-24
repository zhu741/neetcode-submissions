class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        std::vector<int> count_table(26, 0);
        for(int i = 0; i < s.length(); i++){
            count_table[s[i] - 'a']++;
            count_table[t[i] - 'a']--;
        }

        for(auto & count:count_table){
            if (count != 0){
                return false;
            }
        }

        return true;
    }
};
