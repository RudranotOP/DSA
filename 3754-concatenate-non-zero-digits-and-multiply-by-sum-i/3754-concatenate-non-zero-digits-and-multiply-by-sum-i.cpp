class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1;
        
        long long temp = abs((long long)n);
        
        while (temp > 0) {
            int digit = temp % 10;
            
            if (digit != 0) {
                x = x + (digit * multiplier);
                multiplier *= 10;
                sum += digit;
            }
            
            temp /= 10;
        }
        
        return x * sum;
    }
};