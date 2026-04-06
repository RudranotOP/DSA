class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> moveX = {0, 1, 0, -1};
        vector<int> moveY = {1, 0, -1, 0};
        
        unordered_set<string> obstacleMap;
        for (const auto& obstacle : obstacles) {
            string key = to_string(obstacle[0]) + "_" + to_string(obstacle[1]);
            obstacleMap.insert(key);
        }
        
        int currentX = 0;
        int currentY = 0;
        int facingDirection = 0; 
        int maxDistanceSquared = 0;
        
        for (int command : commands) {
            if (command == -2) {
                facingDirection = (facingDirection + 3) % 4;
            } 
            else if (command == -1) {
                facingDirection = (facingDirection + 1) % 4;
            } 
            else {
                for (int step = 0; step < command; ++step) {
                    int nextX = currentX + moveX[facingDirection];
                    int nextY = currentY + moveY[facingDirection];
                    
                    string nextKey = to_string(nextX) + "_" + to_string(nextY);
                    if (obstacleMap.count(nextKey)) {
                        break; 
                    }
                    
                    currentX = nextX;
                    currentY = nextY;
                    
                    int currentDistance = (currentX * currentX) + (currentY * currentY);
                    maxDistanceSquared = max(maxDistanceSquared, currentDistance);
                }
            }
        }
        
        return maxDistanceSquared;
    }
};