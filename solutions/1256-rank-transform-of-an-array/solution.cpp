class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();
        
        if(n == 0){return {};}

        sort(temp.begin(),temp.end());

        unordered_map<int,int> rank;
        rank[temp[0]] = 1;

        for(int i = 1;i < n;i++){
            if(temp[i] == temp[i-1]){
                rank[temp[i]] = rank[temp[i-1]];
            }else{
                rank[temp[i]] = rank[temp[i-1]]+1;
                
            }
        }

        vector<int> res(n);
        for(int i = 0;i < n;i++){
            res[i] = rank[arr[i]];
        }

        return res;
        
    }
};
