class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        if(nums.size()==1) return (long long)nums[0]*nums[0];
        int n=nums.size();
        long long ans =0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=abs(nums[i]);
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            ans-=(long long)nums[i]*nums[i];
        }
        for(int i=n/2;i<n;i++){
            ans+=(long long)nums[i]*nums[i];
        }
        return ans;
    }
};