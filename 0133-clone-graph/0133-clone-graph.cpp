/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> clone;

    void dfs(Node *key){
        Node *new_node = new Node(key->val);
        clone[key] = new_node;
        
        for (auto node: key->neighbors) {
            if (clone.find(node) == clone.end())
                dfs(node);
            new_node->neighbors.push_back(clone[node]);
        }
    }

    Node *cloneGraph(Node *node){
        if(node == NULL)return NULL;
        dfs(node);
        return clone[node];
    }
    
};