class Solution {
private:
    int sumof(int x){
        int sum=0;
        while(x>0){
            int digit=x%10;
            x = x/10;
            sum+=digit;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sumof(nums[i])==i) return i;
        }
        return -1;
    }
};