class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        int n=matches.size();
        // unordered_map<int ,int>win;
        unordered_map<int ,int>lose;
        for(int i=0;i<n;i++){
            lose[matches[i][0]];
            lose[matches[i][1]]++;
        }
        for(auto p:lose){
            if(p.second==0){
                ans[0].push_back(p.first);
            }else if(p.second==1){
                ans[1].push_back(p.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};