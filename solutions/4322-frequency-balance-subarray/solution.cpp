class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){return 0;}

        
        int upper = 1;

        for(int i = 0;i < n;i++){
            unordered_map<int,int> freq,freq_counts;

            for(int j = i;j<n;j++){
                int x = nums[j];
                int old_f = freq[x];
             

                if(old_f > 0){
                    freq_counts[old_f]--;
                    if(freq_counts[old_f] == 0){
                        freq_counts.erase(old_f);
                    }
                }
                freq[x]++;

                int newf = freq[x];
                freq_counts[newf]++;
    
                int len =j-i+1;

                bool valid = false;
    
    

                if(freq_counts.size() == 1){
                    if(freq.size() == 1){valid = true;}
                }
                else if(freq_counts.size() == 2){
                    auto it = freq_counts.begin();
                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;
    
                    int mini = min(f1,f2);
                    int maxi = max(f1,f2);
    
                    if(maxi == 2*mini){
                        valid = true;
                    }
                }
                if(valid){
                    upper = max(upper,len);
                }
            }
        }
        return upper;

        
    }
};
