int func(vector<int>& nums,int mid){
	int sum=0;
	for(int i=0;i<nums.size();i++){
		sum+=ceil((double)nums[i]/(double)mid);
	}
	return sum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
	int maxi=INT_MIN;
	for(int i=0;i<nums.size();i++){
		maxi=max(nums[i],maxi);
		
	}
	int low=1,high=maxi;
	while(low<=high){
		int mid= (low+high)/2;
		
		if(func(nums,mid)<=threshold){
			high=mid-1;
		}else low=mid+1;

	}
	return low;
    }
};