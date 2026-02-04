class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long negativeInfinity = -1e15;
        
        vector<long long> firstRise(n, negativeInfinity);
        vector<long long> fall(n, negativeInfinity);
        vector<long long> secondRise(n, negativeInfinity);
        
        long long maxTotalSum = negativeInfinity;

        for (int i = 1; i < n; i++) {
            long long current = nums[i];
            long long prev = nums[i - 1];

            if (current > prev) {
                firstRise[i] = current + max(prev, firstRise[i - 1]);
            }

            if (current < prev) {
                if (fall[i - 1] != negativeInfinity) {
                    fall[i] = fall[i - 1] + current;
                }
                
                if (firstRise[i - 1] != negativeInfinity) {
                    fall[i] = max(fall[i], firstRise[i - 1] + current);
                }
            }

            if (current > prev) {
                if (secondRise[i - 1] != negativeInfinity) {
                    secondRise[i] = secondRise[i - 1] + current;
                }
                
                if (fall[i - 1] != negativeInfinity) {
                    secondRise[i] = max(secondRise[i], fall[i - 1] + current);
                }
            }

            if (secondRise[i] != negativeInfinity) {
                maxTotalSum = max(maxTotalSum, secondRise[i]);
            }
        }
        
        return maxTotalSum;
    }
};