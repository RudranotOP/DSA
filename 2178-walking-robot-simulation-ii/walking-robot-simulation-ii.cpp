class Robot {
    int gridWidth;
    int gridHeight;
    int totalSteps;
    int perimeter;
    bool hasMoved;
public:
    Robot(int width, int height) {
        gridWidth = width;
        gridHeight = height;
        perimeter = 2 * (width + height - 2);
        totalSteps = 0;
        hasMoved = false;
    }
    
    void step(int num) {
        hasMoved = true;
        totalSteps += num;
        totalSteps %= perimeter;
    }
    
    vector<int> getPos() {
        int remainingSteps = totalSteps;
        
        if (remainingSteps < gridWidth) {
            return {remainingSteps, 0};
        }
        remainingSteps -= (gridWidth - 1);
        
        if (remainingSteps < gridHeight) {
            return {gridWidth - 1, remainingSteps};
        }
        remainingSteps -= (gridHeight - 1);
        
        if (remainingSteps < gridWidth) {
            return {gridWidth - 1 - remainingSteps, gridHeight - 1};
        }
        remainingSteps -= (gridWidth - 1);
        
        return {0, gridHeight - 1 - remainingSteps};
    }
    
    string getDir() {
        if (!hasMoved || totalSteps > 0 && totalSteps < gridWidth) {
            return "East";
        }
        
        if (totalSteps == 0) {
            return "South";
        }

        if (totalSteps >= gridWidth && totalSteps < gridWidth + gridHeight - 1) {
            return "North";
        }
        
        if (totalSteps >= gridWidth + gridHeight - 1 && totalSteps < 2 * gridWidth + gridHeight - 2) {
            return "West";
        }
        
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */