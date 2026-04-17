class Solution {
public:
int rev(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> last;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (last.count(nums[i])) {
                ans = min(ans, i - last[nums[i]]);
            }
            last[rev(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};