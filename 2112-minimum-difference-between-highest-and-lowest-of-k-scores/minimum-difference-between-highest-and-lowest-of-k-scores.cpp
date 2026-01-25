class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int lowestDiff = nums[k-1] - nums[0];

        for(int i = 1; i <= n - k; i++) {
            int currentDiff = nums[i + k - 1] - nums[i];
            if(currentDiff < lowestDiff) {
                lowestDiff = currentDiff;
            }
        }
        
        return lowestDiff;
    }
};