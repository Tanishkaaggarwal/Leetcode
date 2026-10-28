class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        long long ans=0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+'){
            sign=1;
            i++;
        }else{
            sign=1;
        }
        if(i == n) return 0;
        while(i<n && isdigit(s[i])){
            int element=s[i]-'0';
            if(ans > (INT_MAX - element) / 10) {
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
    }
            ans=ans*10+element;
            i++;
        }
        return ans*sign;
    }
};