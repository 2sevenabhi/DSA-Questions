class Solution {
public:

    struct union_find {
        union_find(size_t sz) : _vec(sz + 1) {
            iota(_vec.begin(), _vec.end(), 0);
        }

        void u(int l, int r) {
            _vec[find(l)] = _vec[find(r)];
        }

        int find(size_t pos) {
            return _vec[pos] == pos ? pos : _vec[pos] = find(_vec[pos]);
        }

        vector<int> _vec;
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        union_find uf1(n), uf2(n);
        int erasedEdges = 0;

        // first union all edges with 3
        for(auto & e : edges) 
            switch(e[0]) {
                case 3 : {
                    // if already mathced - just count it
                    if(uf1.find(e[1]) == uf1.find(e[2]))
                        ++erasedEdges;
                    else {
                        uf1.u(e[1], e[2]);
                        uf2.u(e[1], e[2]);
                    }
                }
            }

        // next add edges for separate unions
        for(auto & e : edges) 
            switch(e[0]) {
                case 2 : if(uf2.find(e[1]) == uf2.find(e[2])) ++erasedEdges; else uf2.u(e[1], e[2]); break;
                case 1 : if(uf1.find(e[1]) == uf1.find(e[2])) ++erasedEdges; else uf1.u(e[1], e[2]); break;
            }

        // next count how much sets we have
        int c1 = 0;
        int c2 = 0;
        for(int i = 1; i < n + 1; ++i) {
            c1 += uf1._vec[i] == i ? 1 : 0;
            c2 += uf2._vec[i] == i ? 1 : 0;
        }

        // return count only if we have one set for each group
        return (c1 == 1 && c1 == c2) ? erasedEdges : -1;
    }
};