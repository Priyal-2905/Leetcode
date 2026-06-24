class Solution {
public:
    int solve(int i,int j,string& t,string& s,vector<vector<int>>& dp){
        if(j == t.length()){
            return 1;
        }
        if(i >= s.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int res = solve(i+1,j,t,s,dp);

        if(s[i] == t[j]){
            res += solve(i+1,j+1,t,s,dp);
        }  

        return dp[i][j] = res;      
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = s.length();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(0,0,t,s,dp);
    }
};
