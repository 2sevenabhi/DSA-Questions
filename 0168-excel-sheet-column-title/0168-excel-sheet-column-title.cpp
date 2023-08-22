class Solution {
public:
    string convertToTitle(int cN) {
        
        //Store the alphabets along with their number
        
        unordered_map<int, char>mp; 
        for(int i=1; i<27; i++){
            mp[i] = char(64+i);
            
        }
        
        string s = "";
        
            
        
        while(cN>26){
            int x = cN%26;
            if(x==0)       
                s+= mp[26];  //If x gets exactly divided by 26, that means it is Z
            else
                s+=mp[x];
            
            //Suppose the number given is 52, Output sheet will be AZ for this
            //52%26 = 0 --> The last alphabet will be Z
            //As the x is zero, 52/26 = 2 which will be B hence we have to subtract it by 1
            
            if(x==0)
                cN = cN/26 - 1;
            else
                cN = cN/26;
        }
        s+= mp[cN];
        reverse(s.begin(), s.end());   //Reversing the string
        
        return s;
        
        
    }
};