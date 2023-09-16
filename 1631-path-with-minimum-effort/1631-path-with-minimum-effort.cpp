class Solution {
public:
    bool canReach(vector<vector<int>>& heights, int rows, int cols, int x, int y,
                     int effort, vector<vector<bool>>& vis){
        
        if(x == rows-1 and y == cols-1){
            return true;
        }

        vis[x][y] = true;

        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};

        for(int dir=0; dir<4; dir++){
            int new_x = x + dx[dir];
            int new_y = y + dy[dir];

            if(new_x >= 0 and new_x < rows and new_y >= 0 and new_y < cols and !vis[new_x][new_y]){
                int diff = abs(heights[new_x][new_y] - heights[x][y]);
                if(diff <= effort && canReach(heights, rows, cols, new_x, new_y, effort, vis)){
                    return true;
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        int left = 0, right = 1e6+5, ans = -1;

        while(left <= right){
            int mid = left + (right-left)/2;
            vector<vector<bool>> vis(rows, vector<bool>(cols, false));

            if(canReach(heights, rows, cols, 0, 0, mid, vis)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};