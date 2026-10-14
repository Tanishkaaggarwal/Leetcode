class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int nine=sum/9;
        int rest=sum%9;
        string s="";
        for(int i=0;i<num;i++){
            if(nine>0){
                s+='9';
                nine--;
            }
            else if(rest){
                s+=(rest +'0');
                rest=0;
            }else{
                s+='0';
            }
        }
        return s;
    }
};