class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        unordered_map<char,int>freq;
        int maxfreq=0;
        int ans=0;
        int left=0;
        for(int right=0;right<n;right++){
            freq[answerKey[right]]++;
            maxfreq=max(maxfreq,freq[answerKey[right]]);
            int req=right-left+1 - maxfreq;
            while(req>k){
                freq[answerKey[left]]--;
                left++;
                req=right-left+1 - maxfreq;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};