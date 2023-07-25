class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        //TC:O(logN)
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid-1>=0 && arr[mid-1]<arr[mid] && mid+1<arr.size() && arr[mid]>arr[mid+1])
                return mid;
            else if(mid+1<arr.size() && arr[mid]>arr[mid+1])
                r=mid-1;
            else
                l=mid+1;
        }
        return l;


        //TC:O(N)
        /*
        for(int i=0;i<arr.size();i++)
        {
            if(i-1>=0 && arr[i-1]<arr[i] && i+1<arr.size() && arr[i]>arr[i+1])
                return i;
        }
        return -1;*/
    }
};