class Solution {
public:
    int consecutive(vector<int>& bars){
        if(bars.empty()){return 1;}

        sort(bars.begin(),bars.end());

        int longest = 1;
        int curr = 1;

        for(int i = 1;i < bars.size();i++){
              if(bars[i] == bars[i-1]+1){
                curr++;
                longest = max(curr,longest);
              }else{
                 curr = 1;
              }
        }
        return longest+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       int a = consecutive(hBars);
       int b = consecutive(vBars);

       int l = min(a,b);
       return l*l;
    }
};
