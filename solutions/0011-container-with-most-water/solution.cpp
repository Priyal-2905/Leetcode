class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        int res = 0;

        while(low < high){
            int width = high - low;
            int tall = min(height[high],height[low]);
            int area = width * tall;

            res = max(res,area);

            if(height[low] > height[high]){
                high--;
            }else{
                low++;
            }
        }
        return res;

    }
};
