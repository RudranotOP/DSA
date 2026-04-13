class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int arraySize = nums.size();
        
        for (int distance = 0; distance < arraySize; ++distance) {
            if (start + distance < arraySize && nums[start + distance] == target) {
                return distance;
            }
            if (start - distance >= 0 && nums[start - distance] == target) {
                return distance;
            }
        }
        
        return 0;
    }
};