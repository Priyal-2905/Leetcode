class Solution {
public:
    bool candefeat(long long init,vector<int>& monsters,vector<long long>& bonus){
        int n = monsters.size();
        long long s = init;

        for(int i = 0;i < n;i++){
            if(s+bonus[i] < monsters[i]){
                return false;
            }
            s = max(0LL,s - monsters[i]);
        }

        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> bonus(n+1,0);

        for(auto boost : boosts){
            int l = boost[0];
            int r = boost[1];
            int v = boost[2];

            bonus[l] += v;
            if(r+1 < n){
                bonus[r+1] -= v;
            }
        }

        long long curr = 0;
        for(int i = 0;i < n;i++){
            curr += bonus[i];
            bonus[i] = curr;
        }

        long long low = 0,high = 1e15,ans = high;

        while(low <= high){
            long long mid = low + (high - low)/2;
            if(candefeat(mid,monsters,bonus)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};
