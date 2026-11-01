class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=*min_element(nums.begin(), nums.end());
        int ans=0;
        for(int num:nums){
            ans+=num-min;
        }
        return ans;
    }
};