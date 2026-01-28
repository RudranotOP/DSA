class Solution {
public:
    int numOfWays(int n) {
        long long sameColorPattern = 6;
        long long diffColorPattern = 6;
        long long mod = 1e9 + 7;

        for(int i = 1; i < n; i++) {
            long long nextSame = (sameColorPattern * 3 + diffColorPattern * 2) % mod;
            long long nextDiff = (sameColorPattern * 2 + diffColorPattern * 2) % mod;

            sameColorPattern = nextSame;
            diffColorPattern = nextDiff;
        }

        return (sameColorPattern + diffColorPattern) % mod;
    }
};