/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int low = 0;
        int high = n-1;

        int peak;
        while(low < high){
            int mid = (low + high)/2;

            if(arr.get(mid) < arr.get(mid+1)){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        peak = low;

        if(arr.get(peak) == target){return peak;}

        low = 0;
        high = peak-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr.get(mid) == target){
                return mid;
            }
            else if(arr.get(mid) < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

         low = peak+1;
         high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr.get(mid) == target){
                return mid;
            }
            else if(arr.get(mid) > target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }
};
