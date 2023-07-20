class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        st.push(asteroids[0]);//pushing first element
        for(int i=1;i<asteroids.size();i++){
            if(st.empty()){      //used when stack gets empty 
                st.push(asteroids[i]);
                continue;
            }
            int curr=st.top(); // element at top, current number is
            if(curr>0){        // compared with it
                if(asteroids[i]>0){
                    st.push(asteroids[i]);
                }else{
                    if(curr>abs(asteroids[i])){
                        continue;
                    }
                    else if(curr<abs(asteroids[i])){
                        st.pop();
                        i--;
                        continue;
                    }
                    else{
                        st.pop();
                        continue;
                    }
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};