class Solution {
public:
    int elevatorRequests(int n, vector<int>& req) {
        int n1 = req.size();
        int ans = req[0];

        for(int i = 1;i < n1;i++){
            ans += abs(req[i] - req[i-1]);
        }

        return ans;
    }
};
