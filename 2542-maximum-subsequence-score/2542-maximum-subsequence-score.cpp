static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum{};
        long long mnx{100000L};
        long long res{};
        vector<pair<int,int>> nums{};
        priority_queue<int, vector<int>, std::greater<int>> pq{};

        for(int i = 0; i < nums1.size(); ++i) {
            nums.push_back({nums1[i],nums2[i]});
        }

        sort(nums.begin(), nums.end(),[](auto& lhs, auto& rhs) {
            return lhs.second > rhs.second;
        });

        for(int i = 0; i < nums.size(); ++i)
        {
            #define n1 nums[i].first
            #define n2 nums[i].second
            if(i < k) {
                pq.push(n1);
                sum += n1;
                mnx = n2;
            }
            else {
                res = max(res, sum*mnx);
                if(n1 > pq.top()) {
                    sum = sum - pq.top() + n1;
                    pq.push(n1);
                    pq.pop();
                }
                mnx = n2;
            }
        }

        return max(res,sum*mnx);
    }
};