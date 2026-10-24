class Solution {
public:
    int findDayOfYear (string date){
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> cumMonthDays(13,0);
        cumMonthDays[1] = 31;
        for(int i=2;i<=12;i++){
        cumMonthDays[i]= cumMonthDays[i-1]+monthDays[i-1];
        }
        int month = stoi(date.substr(0,2));
        int days = stoi(date.substr(3));

        return cumMonthDays[month-1]+days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int arriveAliceDay = findDayOfYear(arriveAlice);
        int leaveAliceDay = findDayOfYear(leaveAlice);
        int arriveBobDay = findDayOfYear(arriveBob);
        int leaveBobDay = findDayOfYear(leaveBob);

        int overLapDays = min(leaveAliceDay,leaveBobDay)- max(arriveAliceDay,arriveBobDay)+1;

        return overLapDays >0 ? overLapDays:0;
    }
};