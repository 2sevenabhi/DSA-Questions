class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a || b || c){
            if(( c & 1 ) == 1){ //  if last bit of c is 1
                // if both a's and b's last bit is 0, make any one of them as 1
                if( (a & 1) == 0 && (b & 1) == 0) flips += 1;
            }else{ // if last bit of c is 0
                // if both a's and b's last bit is 0, make both of them as 0
                if( a & 1 ) flips += 1;
                if( b & 1) flips += 1;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};