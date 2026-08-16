class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();

        vector<int> left(n);
        vector<int> right(n);

        int j = 0;
        for(int i = 0;i < n;i++){
            while(station[j] != skill[i]){
                j++;
            }
            left[i] = j;
            j++;
        }

        j = m-1;

        for(int i = n-1; i >= 0;i--){
            while(station[j] != skill[i]){
                j--;
            }
            right[i] = j;
            j--;
        }

        if(n == 1){
            return 0;
        }

        int ans = 0;
        for(int i = 0;i < n-1;i++){
            ans = max(ans,right[i+1] - left[i]);
        }

        return ans;
    }
};
