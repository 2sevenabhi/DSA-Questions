class Solution {
public:
    bool isValid(string s) {
        int stringLen = s.size();  // length of parenthesis
        stack<char>st;  // stack to store parenthesis
        for(int i=0;i<stringLen;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){    // push to stack in case of '(' || '{' || '['
                st.push(s[i]);
            }else{
                if(!st.empty()){   // if stack is empty no need to check stack
                    if(s[i] == ')' && st.top() == '(') st.pop();
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    else return false;
                }else if(st.empty() && (s[i] == '}' || s[i] == ']' || s[i]==')')) return false; // check if stack is empty and s[i] is of wrong side 
            }
        }
        if(!st.empty()) return false; // check if stack has one or more parenthesis left
        return true;
    }
};