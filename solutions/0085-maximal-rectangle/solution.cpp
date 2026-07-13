class Solution {
public:

    int solve(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int ans = 0;

        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty())?i : i-st.top()-1;
                ans = max(ans,width*height);
            }
            st.push(i);
        }
        while(!st.empty()){
            int height = heights[st.top()];
                st.pop();
                int width = (st.empty())?n : n-st.top()-1;
                ans = max(ans,width*height);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n);
        int area = 0;

        for(auto row : matrix){
            for(int j = 0;j < n;j++){
               if(row[j] == '1'){
                    heights[j] += 1;
               } 
               else{
                    heights[j] = 0;
               }   
            }
            area = max(area,solve(heights));
        }
        return area;
    }
};
