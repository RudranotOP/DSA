class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1'000'000'007;

        long long answer = 0;
        int bitLength = 0;

        for (int value = 1; value <= n; value++) {
            if ((value & (value - 1)) == 0) {
                bitLength++;
            }

            answer = ((answer << bitLength) + value) % MOD;
        }

        return (int)answer;
    }
};