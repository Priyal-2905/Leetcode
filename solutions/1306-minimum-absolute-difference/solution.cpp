class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n == 0 || n == 1){return {{}};}
        vector<vector<int>> res;
        int mini = arr[1]-arr[0];
        res.push_back({arr[0],arr[1]});

        for(int i = 2;i < n;i++){
            int diff = arr[i] - arr[i-1];
            if(diff == mini){
                 res.push_back({arr[i-1],arr[i]});
            }
            else if(diff < mini){
                res.clear();
                mini = diff;
                res.push_back({arr[i-1],arr[i]});    
            }
        }
        return res;
    }
};
