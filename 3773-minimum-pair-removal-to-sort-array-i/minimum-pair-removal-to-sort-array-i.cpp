class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (true) {
            bool isSorted = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted) {
                return operations;
            }

            int bestIndex = 0;
            long long minSum = (long long)nums[0] + nums[1];

            for (int i = 1; i < nums.size() - 1; i++) {
                long long currentSum = (long long)nums[i] + nums[i + 1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    bestIndex = i;
                }
            }

            nums[bestIndex] = minSum;
            nums.erase(nums.begin() + bestIndex + 1);
            operations++;
        }
    }
};