class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        int currAlt = 0;

        int n = gain.size();

        for(int i=0; i<n; i++){
            currAlt += gain[i];

            maxAlt = max(maxAlt, currAlt);
        }

        return maxAlt;
    }
};