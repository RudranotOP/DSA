class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_front({0,0});
        int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!dq.empty()){
            auto[r,c]=dq.front();
            dq.pop_front();
            if(r==m-1&&c==n-1){
                return health - dist[m-1][n-1]>=1;

            }
            for(auto& d : dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr >= 0 && nr<m && nc>=0 && nc<n){
                    int cost = grid[nr][nc];
                    if(dist[r][c]+cost<dist[nr][nc]){
                        dist[nr][nc] = dist[r][c] + cost;
                        if(cost==0){
                            dq.push_front({nr,nc});
                        }
                        else{
                            dq.push_back({nr,nc});
                        }
                    }
                }
            }
        }
        return false;
        
    }
};