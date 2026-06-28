class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occu, int freeStart, int freeEnd) {
        sort(occu.begin(),occu.end());
        vector<vector<int>> temp;

        for(auto interval:occu){
            if(temp.empty() || temp.back()[1] + 1 < interval[0]){
                temp.push_back(interval);
            }else{
                temp.back()[1] = max(temp.back()[1],interval[1]);
            }
        }

        vector<vector<int>> result;

        for(auto interval:temp){
            if( interval[1] < freeStart||interval[0]  > freeEnd ){
                result.push_back(interval);
            }
            else if(interval[0] < freeStart && interval[1] <= freeEnd){
                result.push_back({interval[0],freeStart-1});
            }
            else if( interval [0] < freeStart && interval[1] > freeEnd){
                result.push_back({interval[0],freeStart-1});
                result.push_back({freeEnd+1,interval[1]});
            }
            else if(interval[0] >= freeStart && interval[1] > freeEnd){
                result.push_back({freeEnd+1,interval[1]});
            }
            else{
                continue;
            }
        }
        return result;
        
    }
};
