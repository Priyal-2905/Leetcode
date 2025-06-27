class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

     vector<vector<int>> arr(n, vector<int>(n));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int k = 1;

        while(top <= bottom && left <= right){
            
            for(int i=left;i<=right;i++){
                arr[top][i] = k++;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                arr[i][right] = k++;
            }
            right--;

            for(int i=right;i>=left;i--){
                arr[bottom][i] = k++;
            }
            bottom--;
            
            for(int i=bottom;i>=top;i--){
                arr[i][left] = k++;
            }
            left++;
        } 

        return arr;
        
    }
};
