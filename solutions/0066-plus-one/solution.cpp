class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();

      if(digits[n-1]!=9 ){
        digits[n-1]++;
      }
    else{
        int i=n-1;
        while(digits[i]==9 && i>0){
            digits[i--]=0;
        }
        if(i==0 && digits[i]==9){
            digits[i]=1;
            digits.push_back(0);
        }
        else{
            digits[i]++;
        }
    }
     return digits;   
    }
};
