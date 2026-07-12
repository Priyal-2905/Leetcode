class Solution {
public:
    int secondsBetweenTimes(string start, string end) {
        int hour1 = (start[0] - '0')*10 + (start[1] - '0');
        int hour2 = (end[0] - '0')*10 + (end[1] - '0');

        int min1 = (start[3] - '0')*10 + (start[4] - '0');
        int min2 = (end[3] - '0')*10 + (end[4] - '0');

        int sec1 = (start[6] - '0')*10 + (start[7] - '0');
        int sec2 = (end[6] - '0')*10 + (end[7] - '0');

        int total = (hour2 - hour1)*3600;
        total += (min2 - min1)*60;
        total += (sec2 - sec1);

        return total;
        
    }
};
