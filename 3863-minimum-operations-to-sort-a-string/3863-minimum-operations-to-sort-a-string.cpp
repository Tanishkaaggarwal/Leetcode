class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if (ranges::is_sorted(s)) {
            return 0;
        }
        if(n==2){
            return -1;
        }
        char maxi='a';
        char mini = 'z';
        for(char ch:s){
            maxi=max(maxi,ch);
            mini=min(mini,ch);
        }
        if(s[0]==mini || s[n-1]==maxi){
            return 1;
        }
        for(int i=1;i<n-1;i++){
            if(s[i]==maxi || s[i]==mini){
                return 2;
            }
        }
        return 3;
    }
};