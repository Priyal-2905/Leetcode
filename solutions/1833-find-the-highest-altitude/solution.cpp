class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int max_alt = 0;
        int alt = 0;

        for(int i = 1;i <= n;i++){
            alt += gain[i-1];
            max_alt = max(alt,max_alt);
        }

        return max_alt;
    }
};
