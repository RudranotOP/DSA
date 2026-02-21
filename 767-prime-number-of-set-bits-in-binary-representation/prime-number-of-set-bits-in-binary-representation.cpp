class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int primeMask =
            (1 << 2)  | (1 << 3)  | (1 << 5)  | (1 << 7) |
            (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);

        int answer = 0;

        for (int value = left; value <= right; value++) {
            int ones = __builtin_popcount(value);
            if (primeMask & (1 << ones)) {
                answer++;
            }
        }

        return answer;
    }
};