class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        temp.insert(temp.end(), nums.begin(), nums.end());
        vector<int> res(n,-1);
        stack <int> st;

        for(int i = 0;i < 2*n;i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                if(st.top() < n){
                    res[st.top()] = temp[i];
                }
                st.pop();
            }
                st.push(i);
        }

        return res;
        
    }
};
