class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> maxi;
        for(int i=0;i<k;i++){
            while(!maxi.empty() && nums[maxi.back()]<nums[i]){
                maxi.pop_back();
            }
            maxi.push_back(i);
        }
        for(int i=k;i<n;i++){
            ans.push_back(nums[maxi.front()]);
            while(!maxi.empty()&& maxi.front()==i-k){
                maxi.pop_front();
            }
            while(!maxi.empty() && nums[maxi.back()]<nums[i]){
                maxi.pop_back();
            }
            maxi.push_back(i);
        }
        ans.push_back(nums[maxi.front()]);
        return ans;
    }
};