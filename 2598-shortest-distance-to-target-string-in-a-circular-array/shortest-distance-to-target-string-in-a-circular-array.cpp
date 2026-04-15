class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int directDistance = abs(i - startIndex);
                int wrapDistance = n - directDistance;
                
                int currentShortest = min(directDistance, wrapDistance);
                minDistance = min(minDistance, currentShortest);
            }
        }
        
        if (minDistance == INT_MAX) {
            return -1;
        }
        
        return minDistance;
    }
};