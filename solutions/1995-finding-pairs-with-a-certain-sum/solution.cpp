class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int,int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;

        for(auto x:nums2)
            freq[x]++;
    }
    
    void add(int index, int val) {
        freq[arr2[index]]--;

        if(freq[arr2[index]] == 0){
            freq.erase(arr2[index]);
        }

        arr2[index] = arr2[index] + val;
        freq[arr2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0 ;i < arr1.size() ;i++){
           int temp = tot - arr1[i];

           if(freq.count(temp))
            res +=freq[temp];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
