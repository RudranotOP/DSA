class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        int currentParity = 0;
        int evenCount = 1;
        int oddCount = 0;

        long long answer = 0;

        for (int num : arr) {
            if (num % 2 != 0) {
                currentParity ^= 1;
            }
            if (currentParity == 1) {
                answer += evenCount;
                oddCount++;
            }
            else {
                answer += oddCount;
                evenCount++;
            }

            answer %= MOD;
        }

        return answer;
    }
};