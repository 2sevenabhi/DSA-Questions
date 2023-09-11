class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> M;  // group size, people

        for (int i = 0; i < groupSizes.size(); i++) {
            M[groupSizes[i]].emplace_back(i);
        }

        vector<vector<int>> result;

        for (auto it : M) {
            int groupSize = it.first;
            vector<int>& people = it.second;
            vector<int> group(groupSize);
            for (int i = 0; i < people.size(); i++) {
                group[i % groupSize] = people[i];
                if (i % groupSize == groupSize - 1)
                    result.emplace_back(group);
            }
        }

        return result;
    }
};