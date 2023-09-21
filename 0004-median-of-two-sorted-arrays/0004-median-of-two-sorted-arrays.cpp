class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
         
        for(int i = 0 ; i < v2.size() ; i++)
        {
            v1.push_back(v2[i]) ;
        }
        sort(v1.begin(),v1.end()) ;
        int n = v1.size() ;
        if( n % 2 == 0)
        {
            double ans = v1[n/2] + v1[(n/2)-1] ;
            return (double) ans/2 ;
        }else{
            
            return (double) v1[n/2] ;
        }
        
    }
};