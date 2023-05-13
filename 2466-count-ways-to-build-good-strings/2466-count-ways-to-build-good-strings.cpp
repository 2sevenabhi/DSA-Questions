class Solution {
public:

   int countGoodStrings(int low, int high, int zero, int one)
{   
    long long mod = 1e9 + 7;
    long a[high + 1];
    for (int i = 0; i <= high; i++)
    {
        a[i] = 0;
    }
    if (zero == one)
    {
       a[zero] = 2;
        for (int i = zero + 1; i <= high; i++)
        {
            a[i] = ((a[i - zero] % mod) * 2) % mod;
            
        }
    }
    else
    {
        a[zero] = 1;
        a[one] = 1;
        int x = min(one, zero), y = max(zero, one);
        for (int i = x; i <= high; i++)
        {
            int tmp1 = ((i - zero) >= 0) ? (a[i - zero]) : 0;
            int tmp2 = ((i - one) >= 0) ? (a[i - one]) : 0;
            if (i != y && i != x)
                a[i] = (tmp1 % mod  + tmp2 % mod) % mod;
            else
                a[i] += (tmp1 % mod  + tmp2 % mod) % mod;
        }
    }

    long long sum = 0;
    for (int i = low; i <= high; i++)
    {
        sum += a[i] % mod;
    }
    return sum % mod;
}
};