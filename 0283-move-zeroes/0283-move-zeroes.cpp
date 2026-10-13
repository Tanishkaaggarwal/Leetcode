class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        while(left<n &&nums[left]!=0){
            left++;
        }
        for(int right=left+1;right<n;right++){
            if(nums[right]!=0){
                swap(nums[left],nums[right]);
                left++;
            }
            while(left<n &&nums[left]!=0){
            left++;
        }
        }
    }
};