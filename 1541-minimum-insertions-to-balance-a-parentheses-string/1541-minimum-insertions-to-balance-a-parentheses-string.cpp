class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(close % 2==1){
                    open++;
                    close--;
                }
                close+=2;
            }else{
                close--;
                if(close<0){
                    open++;
                    close= 1;
                }
            }
        }
        return open + close;
    }
};