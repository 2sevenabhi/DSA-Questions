//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
       vector<int> row(n , 0);
        vector<int> col(n , 0);
        int maxi = 0 , ans=0;
        for(int i=0; i<n; i++){
            // fill the row
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=matrix[i][j];
            }
            row[i] = sum;
            sum=0;
            for(int j=0; j<n; j++){
                sum+=matrix[j][i];
            }
            col[i] = sum;
            maxi=max(maxi , max(row[i] , col[i]));
        }
        // know we have to make every value equal to maxi
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(row[i]!=maxi && col[j]!=maxi){
                    
                    int oper = 0;
                    if(row[i]>col[j]){
                        oper = maxi-row[i];
                    }
                    else{
                        oper = maxi-col[j];
                    }
                    ans+=oper;
                    row[i]+=oper;
                    col[j]+=oper;
                }
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends