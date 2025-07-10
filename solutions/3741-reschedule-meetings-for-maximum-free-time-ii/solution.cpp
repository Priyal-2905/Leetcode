class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
          vector<int> gap(1, startTime[0]);

        for (int i = 1; i < startTime.size(); ++i)
            gap.push_back(startTime[i] - endTime[i - 1]);

        gap.push_back(eventTime - endTime.back());

        vector<int> Rightmax(gap.size(), 0);

        for (int i = gap.size() - 2; i >= 0; --i)
            Rightmax[i] = max(Rightmax[i + 1], gap[i + 1]);

        int res = 0, Leftmax = 0;
        for (int i = 1; i < gap.size(); ++i) {
            int curGap = endTime[i - 1] - startTime[i - 1];

            if (curGap <= max(Leftmax, Rightmax[i]))
                res = max(res, gap[i - 1] + gap[i] + curGap);

            res = max(res, gap[i - 1] + gap[i]);
            Leftmax = max(Leftmax, gap[i - 1]);
        }
        return res;
    }
};
