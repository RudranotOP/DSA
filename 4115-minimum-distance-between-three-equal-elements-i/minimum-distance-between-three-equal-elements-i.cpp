class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> numberToIndices;
        int arraySize = nums.size();
        
        for (int i = 0; i < arraySize; ++i) {
            numberToIndices[nums[i]].push_back(i);
        }
        
        int minDistanceFound = INT_MAX;
        bool foundGoodTuple = false;
        
        for (auto const& [number, indices] : numberToIndices) {
            if (indices.size() >= 3) {
                foundGoodTuple = true;
                for (int i = 0; i <= (int)indices.size() - 3; ++i) {
                    int currentWindowDistance = 2 * (indices[i + 2] - indices[i]);
                    if (currentWindowDistance < minDistanceFound) {
                        minDistanceFound = currentWindowDistance;
                    }
                }
            }
        }
        
        return foundGoodTuple ? minDistanceFound : -1;
    }
};