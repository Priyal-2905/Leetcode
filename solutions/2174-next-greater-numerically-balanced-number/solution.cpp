class Solution {
public:
   bool isBalanced(int num) {
        string s = to_string(num);
        int freq[10] = {0};
        for (char ch : s) {
            freq[ch - '0']++;
        }
      
        for (int i = 0; i <= 9; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] != i) return false;
        }
        
        return true;
    }
    
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1223334444; i++) {  
            if (isBalanced(i)) return i;
        }
        return -1; 
    }
};
