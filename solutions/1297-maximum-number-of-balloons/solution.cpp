class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> um;

        for(char c : "balloon"){
            um[c] = 0;
        }
        for(char t : text){
            um[t]++;
        }
        int res = INT_MAX;
        for(auto it : um){
            switch(it.first){
                case 'b':
                    res = min(res,it.second);
                    break;
                case 'a':
                    res = min(res,it.second);
                    break;
                case 'l':
                    res = min(res,it.second/2);
                    break;
                case 'o':
                    res = min(res,it.second/2);
                    break;
                case 'n':
                    res = min(res,it.second);
                    break;
                default:
                    continue;

            }
        }
        return res;
    }
};
