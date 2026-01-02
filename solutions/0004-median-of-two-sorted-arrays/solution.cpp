class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> final;
      int n = nums1.size(),m = nums2.size();
      int i = 0,j = 0;

      while(i < n && j < m){
        if(nums1[i] < nums2[j]){
            final.push_back(nums1[i++]);
        }
        else{
            final.push_back(nums2[j++]);
        }
      } 

      while(i < n) 
        final.push_back(nums1[i++]);
      
      while(j < m) 
        final.push_back(nums2[j++]);
      
      double median;

      int mid = (m+n)/2;
      if((m+n)% 2 == 0)
        median = (final[mid] + final[mid-1])/2.0;
      else
        median = final[mid];

      return median;
    }
};
