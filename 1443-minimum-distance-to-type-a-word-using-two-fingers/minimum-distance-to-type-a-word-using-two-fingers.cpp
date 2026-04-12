class Solution {
    int calculateDistance(int firstKey, int secondKey) {
        if (firstKey == 26 || secondKey == 26) return 0;
        return abs(firstKey / 6 - secondKey / 6) + abs(firstKey % 6 - secondKey % 6);
    }

    int findMinPath(const string& word, int currentIndex, int hoveringFinger, vector<vector<int>>& memo) {
        if (currentIndex == word.size()) return 0;
        
        if (memo[currentIndex][hoveringFinger] != -1) return memo[currentIndex][hoveringFinger];

        int targetKey = word[currentIndex] - 'A';
        int lastKey = (currentIndex == 0) ? 26 : (word[currentIndex - 1] - 'A');

        int useLastFinger = calculateDistance(lastKey, targetKey) + 
                            findMinPath(word, currentIndex + 1, hoveringFinger, memo);
                            
        int useHoveringFinger = calculateDistance(hoveringFinger, targetKey) + 
                                findMinPath(word, currentIndex + 1, lastKey, memo);

        return memo[currentIndex][hoveringFinger] = min(useLastFinger, useHoveringFinger);
    }
public:
    int minimumDistance(string word) {
        vector<vector<int>> memo(word.size(), vector<int>(27, -1));
        return findMinPath(word, 0, 26, memo);
    }
};