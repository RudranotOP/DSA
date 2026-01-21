class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        
        for (int number : nums) {
            if (number == 2) {
                result.push_back(-1);
            } else {
                long long bit = 1;
                while ((number & bit) != 0) {
                    bit = bit << 1;
                }
                
                result.push_back(number - (bit / 2));
            }
        }
        
        return result;
    }
};