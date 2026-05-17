class Solution {
public:

    bool solve(vector<int>& arr,int i,vector<bool>& vis){
        int n = arr.size();
        if(i < 0 || i >= n || vis[i]) {
            return false;
        }

        if(arr[i] == 0){return true;}
        vis[i] = true;

        return solve(arr,i+arr[i],vis) || solve(arr,i-arr[i],vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return solve(arr,start, vis);
    }
};
