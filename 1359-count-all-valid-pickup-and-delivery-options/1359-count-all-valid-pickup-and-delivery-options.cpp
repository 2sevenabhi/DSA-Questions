class Solution {
public:
    int countOrders(int n) {
        long long ans=1,m=1000000007 ;
       // if(n==1) return 1;
        for(int i=2;i<=n;i++){
            ans=(((2*i*i)-i)*ans)%m;
        }
        return ans;
    }
};