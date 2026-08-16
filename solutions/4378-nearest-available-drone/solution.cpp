class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int mini = 1e9;
        int n = drones.size();
        for(int i = 0;i < n;i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dist = abs(target[0]-x) + abs(target[1]-y);

            if(dist <= range && dist < mini){
                mini = dist;
                ans = i;
            }
        }

        return ans;
    }
};
