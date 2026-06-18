class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes*6;
        double t = minutes/60.00;
        double hourAngle = (hour%12)*30 + 30*t;

        double res = abs(minAngle-hourAngle);
        return min(res,360.00-res);
    }
};
