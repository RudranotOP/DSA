class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        long long INF = 1e18;
        
        vector<vector<long long>> d(m, vector<long long>(n, INF));
        d[0][0] = 0;
        
        for(int step = 0; step <= k; step++) {
            
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(d[i][j] == INF) continue;
                    
                    if(i + 1 < m) {
                        long long nextVal = d[i][j] + grid[i+1][j];
                        if(nextVal < d[i+1][j]) {
                            d[i+1][j] = nextVal;
                        }
                    }
                    if(j + 1 < n) {
                        long long nextVal = d[i][j] + grid[i][j+1];
                        if(nextVal < d[i][j+1]) {
                            d[i][j+1] = nextVal;
                        }
                    }
                }
            }
            
            if(step == k) break;
            
            map<int, long long> bestSources;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(d[i][j] == INF) continue;
                    int val = grid[i][j];
                    if(bestSources.count(val)) {
                        bestSources[val] = min(bestSources[val], d[i][j]);
                    } else {
                        bestSources[val] = d[i][j];
                    }
                }
            }
            
            long long runningMin = INF;
            for(auto it = bestSources.rbegin(); it != bestSources.rend(); ++it) {
                runningMin = min(runningMin, it->second);
                it->second = runningMin;
            }
            
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int val = grid[i][j];
                    auto it = bestSources.lower_bound(val);
                    if(it != bestSources.end()) {
                        if(it->second < d[i][j]) {
                            d[i][j] = it->second;
                        }
                    }
                }
            }
        }
        
        return (int)d[m-1][n-1];
    }
};