class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(),piles.end());

        int n=piles.size();
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long count=0;
            for(int num:piles){
                count+=num/mid;

                if(num % mid!=0) count++;
            }
            if(count>h){
                s=mid+1;
            }else if(count<=h){
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};