class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        size_t n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long t = mass;

        for(size_t i = 0;i < n;i++){
            if(asteroids[i] > t){
                return false;
            }
            else{
                t += asteroids[i];
            }
        }
        return true;
    }
};
