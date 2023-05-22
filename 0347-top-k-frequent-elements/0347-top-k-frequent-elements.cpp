class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a hash map with the frequencies
        unordered_map<int, int> frequency;
        for(int i = 0 ; i < nums.size() ; i++){
            frequency[nums[i]]++;
        }

        // create a min heap with size k
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> elements;

        // push first k elements in the min heap
        auto it = frequency.begin();
        for(int i = 0 ; i < k ; i++){
            elements.push({it->second, it->first});
            it++;
        }

        // push the remaining elements in the min heap, but keep the size k
        while(it != frequency.end()){
            if(it->second > elements.top().first){
                // pop the top 
                elements.pop();

                // push the greater frequeny
                elements.push({it->second, it->first});
            }
            it++;
        }

        vector<int> output;
        // now the min heap contains our top k elements, so we can take then and store then in an array and retrieve them
        while(!elements.empty()){
            output.push_back(elements.top().second);
            elements.pop();
        }

        return output;
    }
};