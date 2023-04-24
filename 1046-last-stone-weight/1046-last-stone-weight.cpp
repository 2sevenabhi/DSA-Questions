class Solution {
public:
    int lastStoneWeight(vector<int>& a) \
    {
        int n = a.size();
        if (n == 1) return a[0];
        sort(a.begin(), a.end());
        while(a[n - 2] > 0)
        {
            if (a[n-2] < a[n-1])
            {
                a[n-1] = a[n-1] - a[n-2];
                a[n-2] = 0;
            }
            else if (a[n-2] == a[n-1])
            {
                a[n-2] = 0; a[n-1] = 0;
            }
            sort(a.begin(), a.end());
        }
        return a[n-1];
    }
};