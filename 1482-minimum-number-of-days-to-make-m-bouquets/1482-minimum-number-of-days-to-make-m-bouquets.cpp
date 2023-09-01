bool is_Possible(vector<int>& bloomDay, int m, int k,int mid){
    int cnt=0;
    int nofB=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
            cnt++;
        }else{
            nofB+=cnt/k;
            cnt=0;
        }
        
    }
      nofB+=cnt/k;
        return nofB>=m;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1ll*k*1ll;
        int n=bloomDay.size();
        if(val>n) return -1;
        //for min and max element in array
        int mini =INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(bloomDay[i],mini);
            maxi=max(bloomDay[i],maxi);
            
        }
        int low =mini, high= maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(is_Possible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};