class Solution {
private:
    bool ispossible(int mid,vector<int>& nums , int k){
        int stu_count=1;
        int sum=0;
        int i=0;
        int n=nums.size();
        for(int num:nums){
            if(sum+num>mid){
                stu_count++;
                sum=num;
            }else{
                sum+=num;
            }
        }
        return stu_count<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        int s=*max_element(nums.begin(),nums.end());
        int e=sum;
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(mid,nums,k)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};