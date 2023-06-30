class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int left=1, right=cells.size(), ans=0;
        
        //binary search
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(possible(cells,row,col,mid)){
                ans=mid;
                left=mid+1;
            }else
                right=mid-1;
        }
        
        return ans;
    }
    
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    bool possible(vector<vector<int>>& cells , int row , int col , int mid){
        
        vector<vector<int>> grid(row,vector<int>(col,0));
        
        for(int i=0;i<mid;i++)
        { 
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        
        queue<pair<int,int>> q;
        
        for(int c=0;c<col;c++){
            if(grid[0][c]==0){
                q.push({0,c});
                grid[0][c]=1;
            }
        }
        
        while(!q.empty()){
            auto [r,c]=q.front();  q.pop();
            if(r==row-1) return true;
            
            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr>=0 && nc>=0 && nr<row && nc<col && grid[nr][nc]==0) 
                {
                    q.push({nr,nc});
                    grid[nr][nc]=1;
                }
                
            }
        }
        return  false;
    }
    
};