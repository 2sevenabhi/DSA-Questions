const static auto boost = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}
();

class Solution {
    bool is_safe(int idx, vector<int> &processed, vector<bool> &visited, vector<vector<int>>& graph)
    {
        if(processed[idx] != -1)
        {
            return processed[idx];
        }
        if(graph[idx].empty())
        {
            return true;
        }
        if(visited[idx])
        {
            return false;
        }

        visited[idx] = true;
        bool safety = true;
        for(auto &adj : graph[idx])
        {
            safety = is_safe(adj, processed, visited, graph);
            if(!safety)
            {
                break;
            }
        }
        visited[idx] = false;
        return safety ? processed[idx] = true : processed[idx] = false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<bool> visited(graph.size(), false);
        vector<int> processed(graph.size(), -1);
        vector<int> safe_nodes;

        for(size_t i = 0; i < graph.size(); ++i)
        {
            if(is_safe(i, processed, visited, graph))
            {
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
    }
};