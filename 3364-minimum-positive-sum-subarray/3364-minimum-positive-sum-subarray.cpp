class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minimumSum = INT_MAX;

        for(int start = 0; start<n; start++){
            int currentSum = 0;
            for(int end = start; end < n && end <start+r; end++){
                currentSum += nums[end];
                int length = end-start+1;
                if(length>=l && currentSum > 0){
                    minimumSum = min(minimumSum, currentSum);
                }
            }
        }
        return minimumSum == INT_MAX ? -1 : minimumSum;
        
    }
};