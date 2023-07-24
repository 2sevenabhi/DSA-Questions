class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        else if(n==-1){
            double r = 1/x;
            return r;
        }
        else{
            if(n%2==0){
                double p = myPow(x,n/2);
                return p*p;
            }
            else{
                double p=myPow(x,n/2);
                if(n<0){
                    return p*p/x;
                }
                else{
                    return p*p*x;
                }
            }
        }
    }
};