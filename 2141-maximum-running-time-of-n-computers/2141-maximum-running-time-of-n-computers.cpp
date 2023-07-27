class Solution {
public:
  long long maxRunTime(int n, vector<int>& batteries) {
    std::nth_element(batteries.begin(), batteries.end() - n, batteries.end());
    std::sort(batteries.end() - n + 1, batteries.end());
    int64_t power = std::accumulate(batteries.begin(), batteries.end() - n + 1, 0LL);
    const int start = batteries.size() - n;
    int used = 1;  // batteris at [start, start + used) can be used up.
    while (used < n) {
      int battery = batteries[start + used];  // next battery
      if (power / used < battery) {
        break;  // it will not be used up.
      }
      power += battery;
      ++used;
    }
    return power / used;
  }
};