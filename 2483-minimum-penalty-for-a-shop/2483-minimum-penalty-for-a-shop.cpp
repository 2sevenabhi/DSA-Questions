class Solution {
public:
    int bestClosingTime(string customers) {
        int maxcount=0;
        int count=0;
        int besttime=0;
        for (int i=0;i<customers.size();i++){
            if (customers[i]=='Y')count++;
            else count--;
            if(maxcount<count){
                maxcount=count;
                besttime=i+1;//pos not index
            }
        }

        return besttime; 
    }
};