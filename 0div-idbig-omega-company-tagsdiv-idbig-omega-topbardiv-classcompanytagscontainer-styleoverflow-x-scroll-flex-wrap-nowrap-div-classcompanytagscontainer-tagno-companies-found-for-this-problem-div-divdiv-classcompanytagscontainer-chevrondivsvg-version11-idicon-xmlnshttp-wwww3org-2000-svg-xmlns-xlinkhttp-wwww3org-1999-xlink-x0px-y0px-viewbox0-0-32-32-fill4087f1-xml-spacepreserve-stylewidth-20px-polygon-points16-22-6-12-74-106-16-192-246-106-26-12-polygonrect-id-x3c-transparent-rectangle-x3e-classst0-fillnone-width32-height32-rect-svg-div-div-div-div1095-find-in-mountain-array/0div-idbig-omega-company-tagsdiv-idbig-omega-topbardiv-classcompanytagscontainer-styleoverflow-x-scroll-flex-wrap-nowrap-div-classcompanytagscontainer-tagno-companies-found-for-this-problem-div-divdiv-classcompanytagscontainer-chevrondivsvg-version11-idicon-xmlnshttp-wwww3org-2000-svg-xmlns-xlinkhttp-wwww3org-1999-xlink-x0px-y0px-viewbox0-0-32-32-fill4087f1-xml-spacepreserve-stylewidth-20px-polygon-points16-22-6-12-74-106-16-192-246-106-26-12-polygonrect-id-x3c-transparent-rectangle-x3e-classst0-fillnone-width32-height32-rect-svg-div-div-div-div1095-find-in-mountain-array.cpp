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
    int findPeak(MountainArray &mountainArr){
        
        int n = mountainArr.length();
        int l = 0, r = n-1;
        while(l<r){
            
            int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
        
    }
    int findTarget1(int l, int r, MountainArray &mountainArr, int target){
        
        int count = -1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid)==target){
                count = mid;
                break;
            }
            if(mountainArr.get(mid)<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            
        }
        return count;
    }
    int findTarget2(int l, int r, MountainArray &mountainArr, int target){
        
        int count = -1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid)==target){
                count = mid;
                break;
            }
            if(mountainArr.get(mid)<target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return count;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        
        int idx = findPeak(mountainArr);
        
        int result = findTarget1(0, idx, mountainArr, target);
        
        if(result==-1){
            result = findTarget2(idx+1, n-1, mountainArr, target);
        }
        
        return result;
    }
};