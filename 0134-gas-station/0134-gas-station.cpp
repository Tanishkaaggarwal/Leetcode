class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficiet=0;
        int balance=0;
        int startindex=0;
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficiet+=balance;
                startindex=i+1;
                balance=0;
            }
        }
        if(deficiet+balance>=0){
            return startindex;
        }else{
            return -1;
        }
    }
};