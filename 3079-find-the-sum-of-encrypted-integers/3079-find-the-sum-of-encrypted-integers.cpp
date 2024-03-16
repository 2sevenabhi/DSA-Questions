class Solution {
public:
    
    
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
           int num=nums[i];
            string s= to_string(num);
            int greater=0;
            for(int i=0;i<s.length();i++){
                int ele=s[i]-'0';
                greater=max(greater,ele);
                
            }
            string str="";
            for(int i=0;i<s.length();i++){
                str+= to_string(greater);
            }
            nums[i]=stoi(str);
        }
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans;
    }
};