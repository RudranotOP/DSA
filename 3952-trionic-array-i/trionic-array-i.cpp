class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;

        int i = 0;
        while(i+1<n && nums[i] < nums[i+1]){
            i++;
        }
        if(i==0 || i==n-1) return false;

        int peak = i;
        while(i+1<n && nums[i]>nums[i+1]){
            i++;
        }

        if(i==peak || i==n-1) return false;

        while(i+1<n&&nums[i]<nums[i+1]){
            i++;
        }
        return i == n-1;
    }
};