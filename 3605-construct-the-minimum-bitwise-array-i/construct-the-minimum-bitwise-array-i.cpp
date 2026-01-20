class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;

        for (int number : nums) {
            if (number == 2) {
                result.push_back(-1);
            } else {
                int bitIndex = 0;
                while ((number >> bitIndex) & 1) {
                    bitIndex++;
                }
                
                int bitToFlip = bitIndex - 1;
                result.push_back(number ^ (1 << bitToFlip));
            }
        }

        return result;
    }
};