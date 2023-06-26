class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;
        int left = 0;
        int right = n-1;
        priority_queue <int, vector<int>, greater<int> > pqLeft; 
        priority_queue <int, vector<int>, greater<int> > pqRight; 

        while(left < right && candidates > 0){
            pqLeft.push(costs[left]);
            pqRight.push(costs[right]);
            left++;
            right--;
            candidates--;
        }

        
        if(candidates > 0 && left == right){
            pqLeft.push(costs[left]);
            left++;
        }

        
        while(left <= right && k > 0){
            if(pqLeft.top() <= pqRight.top()){
                ans += pqLeft.top();
                pqLeft.pop();
                pqLeft.push(costs[left]);
                left++;
            }else{
                ans += pqRight.top();
                pqRight.pop();
                pqRight.push(costs[right]);
                right--;
            }
            k--;
        }

               while(k > 0){
            if(!pqLeft.empty() && !pqRight.empty()){
                if(pqRight.top() >= pqLeft.top()){
                    ans += pqLeft.top();
                    pqLeft.pop();
                }else{
                    ans += pqRight.top();
                    pqRight.pop();
                }
            }else if(!pqLeft.empty()){
                ans += pqLeft.top();
                pqLeft.pop();
            }else{
                ans += pqRight.top();
                pqRight.pop();
            }
            k--;
        }
        return ans;
    }
};