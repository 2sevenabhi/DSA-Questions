//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
   string multiplyStrings(string s1, string s2) {
        bool neg1=0,neg2=0;
        
        // find whether given numbers are negative or not.
        for(int i=0 ; i<s1.size() ;i++)
            if(s1[i]=='-'){
                s1.erase(s1.begin()+i);
                neg1=1; break; }
        
        for(int i=0 ; i<s2.size() ; i++)
            if(s2[i]=='-'){
                s2.erase(s2.begin()+i); 
                neg2=1; break; }
        
        // reverse the numbers in string.
        int n1=s1.size();
        int n2=s2.size();
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string product(n1+n2,'0');

        for(int i=0;i<n2;i++){
            int carry=0;
            int num=s2[i]-48;
            for(int j=0;j<n1;j++){
               int temp=s1[j]-48;
               //store in product[i+j].
               int prod=num*temp+carry;
               carry = (product[i+j]-'0' + (prod%10))/10 + prod/10;
               product[i+j] = (product[i+j] - '0' + (prod%10))%10 + '0';
            }
            product[i+n1]=carry+'0';
        }
        for(int i=n1+n2-1;i>=0;i--){
            if(product[i]!='0'){
                // erase trailing zeroes.
                product.erase(product.begin()+i+1,product.end());
                // put negative sign.
                if(neg1^neg2) product.push_back('-');
                // reverse the product array to  get the desired output.
                reverse(product.begin(),product.end());
                break;
            }
            // if product of number is zero.
            if(i==0){
                product.clear();
                product.push_back('0');
            }
        }
        return product;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends