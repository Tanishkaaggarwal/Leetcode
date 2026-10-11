class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        int left=0;
        int maxfreq=0;
        unordered_map<char,int>freq;
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            maxfreq=max(maxfreq,freq[s[right]]);
            int req=(right-left+1)-maxfreq;
            while(req>k){
                freq[s[left]]--;
                left++;
                req=(right-left+1)-maxfreq;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};