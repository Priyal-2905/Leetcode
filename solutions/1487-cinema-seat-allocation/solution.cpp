class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> mp;
        for(auto seat  : reservedSeats){
            int row = seat[0];
            int col = seat[1];

            if(col >= 2 && col <= 9){
                mp[row].insert(col);
            }
        }

        for(auto [row,seats] : mp){
            bool first = true;
            bool second = true;
            bool third = true;

            for(int i = 2;i <= 5;i++){
                if(seats.count(i)){
                    first = false;
                    break;
                }
            }

            for(int i = 4;i <= 7;i++){
                if(seats.count(i)){
                    second = false;
                    break;
                }
            }

            for(int i = 6;i <= 9;i++){
                if(seats.count(i)){
                    third = false;
                    break;
                }
            }

            if(first && third){
                ans += 2;
                continue;
            }
            if(first || second || third){
                ans++;
            }
        }
        ans += (n - mp.size())*2;
        return ans;
    }
};
