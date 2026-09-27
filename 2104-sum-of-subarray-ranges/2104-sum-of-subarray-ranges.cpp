using ll = long long;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> PSE(n);
        vector<int> NSE(n);
        vector<int> PGE(n);
        vector<int> NGE(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            NSE[i]= st.empty()? n : st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i] ) st.pop();
            PSE[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i] ) st.pop();
            PGE[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i] ) st.pop();
            NGE[i]= st.empty() ? n : st.top();
            st.push(i);
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            ll maxi=static_cast<ll>(i - PGE[i] ) * (NGE[i] - i)* nums[i];
            ll mini=static_cast<ll>(i - PSE[i] ) * (NSE[i] - i)* nums[i];
            sum+=maxi-mini;
        }
        return sum;
    }
};