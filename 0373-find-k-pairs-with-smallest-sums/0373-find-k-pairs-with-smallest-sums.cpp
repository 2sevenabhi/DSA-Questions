class Solution {
public:
    struct Vector3{
        int x,y,z;
    };
    struct CompareVector3 {
        bool operator()(Vector3& v1,Vector3& v2) {
            int sum1=v1.x+v1.y;
            int sum2=v2.x+v2.y;
            return sum1>sum2;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        priority_queue<Vector3,vector<Vector3>,CompareVector3>q;
        long long n1=v1.size();
        long long n2=v2.size();
        for(int i=0;i<n1;i++){
            Vector3 temp={v1[i],v2[0],0};
            q.push(temp);
        }
        vector<vector<int>>v;
        long long w=(n1*n2);
        if(w>k) w=k;
        while(v.size()<int(w)){
            Vector3 temp=q.top();
            q.pop();
            vector<int> k={temp.x,temp.y};
            v.push_back(k);
            if(temp.z<n2-1){
                Vector3 e={temp.x,v2[temp.z+1],temp.z+1};
                q.push(e);
            }
        }
        return v;
    }
};