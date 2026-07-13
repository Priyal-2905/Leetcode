class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
       
        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty())? i : i - st.top()-1;
                area = max(area,height*width);
            }
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int width = (st.empty())? n : n - st.top()-1;
            area = max(area,height*width);
        }

        return area;
    }
};
