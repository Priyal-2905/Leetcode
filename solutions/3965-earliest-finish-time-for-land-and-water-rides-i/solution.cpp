class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int res = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            int landfin = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterbeg = max(landfin, waterStartTime[j]);
                int totalfin = waterbeg + waterDuration[j];

                res = min(res, totalfin
                );
            }
        }

       
        for (int i = 0; i < waterStartTime.size(); i++) {
            int waterfin = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < landStartTime.size(); j++) {
                int landbeg = max(waterfin, landStartTime[j]);
                int totalfin = landbeg + landDuration[j];

                res = min(res , totalfin);
            }
        }

        return res;
    }
};
