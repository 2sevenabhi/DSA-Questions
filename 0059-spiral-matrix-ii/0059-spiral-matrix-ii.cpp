class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector< vector<int> > m(n,vector<int>(n,0)); //initializing ans vector with zeroes
        int p=1,i,j;    //p is the value which is consistently being written in matrix
         
        for(int x=0;x<n;x++)
        {
            i=x;        //right direction
            for(j=i;j<n && m[i][j]==0 ;j++)    //this will go for [00 01 02]
            {
                m[i][j]=p++;
            }
            
            j=n-1-x;  //down direction
            for( i=i+1;i<n && m[i][j]==0 ;i++)  //this will go for [21 22 ] , after the first loop to right, we move our i to one row down
            {
               m[i][j]=p++;
            }
            
            i=n-1-x;   //left direction
           for(j=i-1;j>=0 && m[i][j]==0 ;j--)  //after the down loop,we'll end up with j=n-1(in first traversal), so we're moving our j to one step back 
           {

                m[i][j]=p++;
           }
            
          j=x;       //top direction
          for( i=i-1;i>=0 && m[i][j]==0  ;i--)  //after moving all left we'll end up on first row where we haven't filled before (which we're constantly checking by m[i][j]==0), so we move our i by 1 i.e. i=i-1
          {
               m[i][j]=p++;
          }
              
        }
        
        return m;
       
    }
};