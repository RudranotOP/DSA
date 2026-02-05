class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int arrayLength = nums.size();
        vector<int> transformedArray(arrayLength);

        for (int currentIndex = 0; currentIndex < arrayLength; currentIndex++) {
            int stepsToMove = nums[currentIndex];
            int targetIndex = (currentIndex + stepsToMove) % arrayLength;

            if (targetIndex < 0) {
                targetIndex += arrayLength;
            }

            transformedArray[currentIndex] = nums[targetIndex];
        }

        return transformedArray;
    }
};