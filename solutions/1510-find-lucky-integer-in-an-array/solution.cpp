class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        int n = arr.size();

        for(int i = 0 ; i < n ; i++){
            m[arr[i]]++;
        }
        int lucky = -1;
        for(auto x : m){
            if( x.second == x.first )
                lucky = max(lucky , x.first);
        }
        return lucky;
    }
};
