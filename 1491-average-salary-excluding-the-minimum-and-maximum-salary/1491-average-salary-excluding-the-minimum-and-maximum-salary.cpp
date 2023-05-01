class Solution {
public:
    double average(vector<int>& salary) {
      int n = salary.size();
      double maxi = INT_MIN, mini = INT_MAX;
      for(int i=0; i<n; i++){
         if(salary[i]>maxi){maxi = salary[i];}
          if(salary[i]<mini){mini = salary[i];}
      }
        double sum=0;
       for(int i=0; i<n; i++){
           sum +=salary[i];
              } 
         sum -= (mini+maxi); 
        sum = sum/(n-2); 
        return sum;
    }
};