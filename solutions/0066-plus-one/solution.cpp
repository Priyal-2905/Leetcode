class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int carry = 1;
      int m = digits.size()-1;

      if(digits[m] != 9){
        digits[m] += 1;
        return digits;
      }

      for(int i = m;i >= 0;i--){
         if(digits[i]+carry > 9){
            digits[i] = 0;
         }
         else{
            digits[i] += carry;
            carry = 0;
            break;
         }
      }
      if(carry){
        digits[0] = 0;
        digits.insert(digits.begin(),1);
      }
      return digits;
    }
};
