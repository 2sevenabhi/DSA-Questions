int func(vector<int> &weights, int days,int capacity){
    int day=1;
   int load=0;
   for(int i=0;i<weights.size();i++){
      if(load+weights[i]>capacity){
          day=day+1;
           load=weights[i];
          

      } 
     else{
           load+=weights[i];
       }
   }
   return day;

}


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         int mini=INT_MIN;
    int sum=0;
    for(int i=0;i<weights.size();i++){
        mini=max(weights[i],mini);
        sum+=weights[i];
    }
    int low=mini,high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        int midN=func(weights,days,mid);
        if(midN<=days){
            high=mid-1;
        }else low=mid+1;

    }
    return low;
    }
};