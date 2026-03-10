class Solution {
public:
static const int MOD = 1000000007;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<int>> endWithZero(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> endWithOne(zero + 1, vector<int>(one + 1, 0));

        for (int zerosUsed = 1; zerosUsed <= min(zero, limit); zerosUsed++) {
            endWithZero[zerosUsed][0] = 1;
        }

        for (int onesUsed = 1; onesUsed <= min(one, limit); onesUsed++) {
            endWithOne[0][onesUsed] = 1;
        }

        for (int zerosUsed = 1; zerosUsed <= zero; zerosUsed++) {
            for (int onesUsed = 1; onesUsed <= one; onesUsed++) {
                long long waysEndingInZero =
                    endWithZero[zerosUsed - 1][onesUsed] +
                    endWithOne[zerosUsed - 1][onesUsed];

                if (zerosUsed - limit - 1 >= 0) {
                    waysEndingInZero -= endWithOne[zerosUsed - limit - 1][onesUsed];
                }

                waysEndingInZero %= MOD;
                if (waysEndingInZero < 0) waysEndingInZero += MOD;
                endWithZero[zerosUsed][onesUsed] = (int)waysEndingInZero;

                long long waysEndingInOne =
                    endWithOne[zerosUsed][onesUsed - 1] +
                    endWithZero[zerosUsed][onesUsed - 1];

                if (onesUsed - limit - 1 >= 0) {
                    waysEndingInOne -= endWithZero[zerosUsed][onesUsed - limit - 1];
                }

                waysEndingInOne %= MOD;
                if (waysEndingInOne < 0) waysEndingInOne += MOD;
                endWithOne[zerosUsed][onesUsed] = (int)waysEndingInOne;
            }
        }

        return (endWithZero[zero][one] + endWithOne[zero][one]) % MOD;
    }
};