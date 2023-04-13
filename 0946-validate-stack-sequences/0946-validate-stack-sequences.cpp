class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        // Initialise 'j' pointer for 'popped' vector
        int j = 0;
        for(int i = 0; i < pushed.size(); i++){
            // Push the element in stack
            st.push(pushed[i]);
            // Check if stack is not empty and top element of stack matches with popped[j]
            while(st.size() && st.top() == popped[j]){
                // if it matches, pop the top element of stack
                st.pop();
                // Increase the j by 1, to traverse the 'popped' vector
                j++;
            }
        }
		// Since pushed and popped are of equal size, so, if the sequence is correct then stack must be empty at last
        return st.size() == 0;
    }
};