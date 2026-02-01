class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int score = nums[0];

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for(int i = 1; i<n; i++){
            if(nums[i]<firstMin){
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if(nums[i]<secondMin){
                secondMin = nums[i];
            }
        }
        return score +firstMin+secondMin;
    }
};