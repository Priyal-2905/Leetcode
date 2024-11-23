class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0){
            return false;
        }else{
           long long int temp = x;
           long long int rev  = 0;

           while(temp != 0){
            int current = temp%10;
            rev = rev*10 + current;
            temp /= 10;
           }

           return (rev == x) ;
        }
        
        

       

        
    }
};
