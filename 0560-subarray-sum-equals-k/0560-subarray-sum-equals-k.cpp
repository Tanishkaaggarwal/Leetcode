class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> count;
        count[0]=1;
        int currsum=0;
        int ans=0;
        for(int num : nums){
            currsum+=num;
            if(count.find(currsum-k)!=count.end()){
                ans+=count[currsum-k];
            }
            count[currsum]++;
            
        }
        return ans;
    }
};