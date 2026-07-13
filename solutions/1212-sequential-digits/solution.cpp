class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> res;

        for(int k = 1;k <= 9;k++){
            int  i = 0;
            while(i+k <= 9){
                int num = stoi(s.substr(i, k));
                if(num >= low && num <= high){
                    res.push_back(num);
                }
                i++;
            }
        }

        return res;
    }
};
