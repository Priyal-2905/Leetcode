class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int sum = 0; 
        for(int &num: nums){
            int tmp_sum = 1 + num;      
            int counter = 2;       
            for(int i = 2; i*i <= num; i++){
                if(num % i == 0){
                    tmp_sum += i;
                    counter++;
                    int opposite = num / i;

                    if(opposite == i) {break;}
                    
                    tmp_sum += opposite;
                    counter++;
                }
            }
            if(counter == 4){
                sum += tmp_sum;
            }
        }
        return sum;
    }
    
};
