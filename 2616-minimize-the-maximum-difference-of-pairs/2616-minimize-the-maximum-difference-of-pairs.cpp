class Solution {
public:
int n;
bool canbepaired(vector<int>& nums,int mid,int p){
    int i=0;
    int count_pairs=0;
    while(i<n-1){
        if(nums[i+1]-nums[i]<=mid){
            count_pairs++;
            i+=2;

        }else{
            i++;
        }
    }
    return count_pairs>=p;
}
    int minimizeMax(vector<int>& nums, int p) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[n-1]-nums[0];
        int result=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canbepaired(nums,mid,p)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
// #O(N*LOG(M))
    }
};