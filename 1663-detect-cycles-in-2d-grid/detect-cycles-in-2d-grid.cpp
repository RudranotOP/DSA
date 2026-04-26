class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) continue;

                queue<tuple<int,int,int,int>> q;
                q.push({i, j, -1, -1});
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto [x, y, px, py] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];

                        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if (grid[nx][ny] != grid[x][y]) continue;

                        if (!vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            q.push({nx, ny, x, y});
                        } else if (nx != px || ny != py) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};