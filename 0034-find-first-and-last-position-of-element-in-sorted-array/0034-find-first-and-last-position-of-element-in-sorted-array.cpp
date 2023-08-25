class Solution {
public:
    int firstOccurence(vector<int> &nums,int n,int target){
    int low=0,high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (target == nums[mid]) {
          first = mid;
          high = mid - 1;

        } else if (nums[mid] < target) {
          low = mid + 1;
        } 
        else high=mid-1;
    }
    return first;

}
int lastOccurence(vector<int> &nums,int n,int target){
    int low=0,high=n-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (target==nums[mid]) {
          last=mid;
          low=mid+1;

        }
       else if (nums[mid] < target) {
          low = mid + 1;
        } 
        else high=mid-1;
    }
    return last;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
          int f = firstOccurence(nums, n, target);
    if (f == -1){
        return {-1, -1};
    }
    int l= lastOccurence(nums,n,target);
    return {f,l};
   }
    
};