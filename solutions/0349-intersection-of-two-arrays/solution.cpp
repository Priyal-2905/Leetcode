class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums2.begin(),nums2.end());
        unordered_set<int> temp;
        vector<int> res;

        for(int i=0;i<nums1.size();i++){
            if(s.count(nums1[i])){
                temp.insert(nums1[i]);
            }
        }
        for(auto m:temp)
            res.push_back(m);
    
        return res;
    }
    
};
