class Solution {
public:
    vector<int> parent,rank;
    int findPar(int node)
    {
        if(parent[node]==node)
        return node;
        return parent[node] = findPar(parent[node]);
    }
    void Union(int x,int y)
    {
        int u = findPar(x);
        int v = findPar(y);
        if(rank[u]>=rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
        else 
        {
            parent[u] = v;
            rank[v]++;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string s1 = strs[i];
                string s2 = strs[j];
                int cnt=0;
                for(int k=0;k<s1.size();k++)
                {
                    if(s1[k]!=s2[k])
                    cnt++;
                }
                if(cnt<=2)
                {
                    if(parent[i]!=parent[j])
                    Union(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            ans++;
        }
        return ans;
    }
};