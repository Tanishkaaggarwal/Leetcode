class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n+1,0);
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        vector<int> ans;
        for(int i=1;i<n+1;i++){
            if(count[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};