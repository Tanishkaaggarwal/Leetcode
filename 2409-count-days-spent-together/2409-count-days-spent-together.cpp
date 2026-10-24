class Solution {
private:
    int solve(string date, const vector<int>& prefixsum) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        // prefixsum[month - 1] contains the total days in all previous months
        return prefixsum[month - 1] + day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>prefixsum(1,0);
        for(int day:days){
            prefixsum.emplace_back(prefixsum.back()+day);
        }
        int num1=solve(arriveAlice,prefixsum);
        int num2=solve(leaveAlice,prefixsum);
        int num3=solve(arriveBob,prefixsum);
        int num4=solve(leaveBob,prefixsum);
        return max(0,min(num2,num4)-max(num1,num3)+1);
    }
};