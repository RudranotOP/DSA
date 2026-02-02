class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) return {-1, -1};
        
        int last = findBound(nums, target, false);
        return {first, last};
    }
    private:
    int findBound(vector<int>& numbers, int target, bool lookingForFirst) {
        int left = 0;
        int right = numbers.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (numbers[mid] == target) {
                result = mid;
                if (lookingForFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (numbers[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

};