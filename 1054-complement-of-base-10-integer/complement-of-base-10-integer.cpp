class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int allOnesMask = 0;
        int currentValue = n;

        while (currentValue > 0) {
            allOnesMask = (allOnesMask << 1) | 1;
            currentValue >>= 1;
        }

        return allOnesMask ^ n;
    }
};