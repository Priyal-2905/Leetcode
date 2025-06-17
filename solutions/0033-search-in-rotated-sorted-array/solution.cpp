class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
       while(low<=high){
        int mid=(high+low)/2;

         if(arr[mid]==target) return mid;

        else if(arr[low]<=arr[mid]){

            if(target <= arr[mid] && arr[low] <=target )
                high = mid-1;
            else if(arr[low]==target)
                return low;

            else
             low = mid+1;
        }
        else{
            if(target<arr[high]&& target>arr[mid]){
                low = mid+1;
            }
            else if(arr[high]==target)
                return high;
            else
                high = mid-1;
        }
         
       }
        return -1;
    }
};
