class Solution {
public:
    string simplifyPath(string s) {
        string res; 
        int n = s.size();
        
        // If the size is 1, return '/'
        if(n == 1) return "/";
        
        // There might be a case where the absolute path does not end with '/' , so Add '/' for simpler calculation
        if(s[n - 1] != '/') s.push_back('/');
        
        // Take temporary string to check for '.' or '..' , you may also use temporary integer
        string temp = "";
        
        for(int i = 0; i < s.size(); i++){
            // There are two cases 
            // 1) s[i] == '/'
            // 2) s[i] != '/'
            
            // We will do operation when ever we reached '/' except for i = 0
            
            if(s[i] != '/'){
                // Update the temp string and result string
                string t = "";
                t += s[i];
                res += t;
                temp += t;
                
            } else if (i != 0){
                // Since we cannot have continuous '/', if the result string ended with '/', then continue
                if(res.back() == '/') continue;
                
                if(temp == "."){
                    // If there is one '.', remove last two elements from the result
                    res.pop_back();
                    res.pop_back();
                    
                } else if(temp == ".."){
                    // If there is two '..', then remove until we remove two '/' from the result
                    int c = 0;
                    while(c < 2){
                        if(res.back() == '/') c++;
                        if(res.size() == 0) break;
                        res.pop_back();
                    }
                }
                // Make temp string as empty
                temp = "";
                res.push_back('/');
            } else {
                // Case when i = 0
                res.push_back(s[i]);
            }
        }
        
        // Finally remove the last '/' in the result
        if(res.size() > 1) res.pop_back();
        return res;
    }
};
