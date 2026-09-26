class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store knowledge in map
        for (auto &entry : knowledge) {
            mp[entry[0]] = entry[1];
        }

        string ans = "";
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                i++;

                string word = "";

                while (s[i] != ')') {
                    word += s[i];
                    i++;
                }

                // Key found
                if (mp.find(word) != mp.end()) {
                    ans += mp[word];
                } 
                else {
                    ans += '?';
                }

                i++; // skip ')'
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};