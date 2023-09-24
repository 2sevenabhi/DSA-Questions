class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
      double ch[101][101] ={0.0}; 
       ch[0][0]=double(poured);
       for(int i=0;i<100;i++){
           for(int j=0;j<=i;j++){
             if(ch[i][j]>1.0){
                  double x= ch[i][j];
                  ch[i][j]=1.0;
              x=x-1.0;
              ch[i+1][j]+=x/2;
              ch[i+1][j+1]+=x/2;
             }     
           }
       }
           return ch[query_row][query_glass];


    }
};