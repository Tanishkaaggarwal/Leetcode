class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Sort intervals based on the starting value
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        // Push the first interval to start comparing
        ans.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // Get a reference to the last inserted interval in our answer list
            vector<int>& lastInterval = ans.back();
            
            // If the current interval overlaps with the last one in ans
            if (intervals[i][0] <= lastInterval[1]) {
                // Update the end of the last interval to the maximum end value
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                // No overlap, so we add the current interval to ans
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};