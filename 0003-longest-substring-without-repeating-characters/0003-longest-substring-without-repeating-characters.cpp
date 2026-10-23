class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int maxi=0;
        int ans=0;
        unordered_map<char,int> freq;
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
                
            }
            maxi=right-left+1;
            ans=max(ans,maxi);
        }
        return ans;
    }
};