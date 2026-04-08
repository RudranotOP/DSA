class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1000000007;
        int B = 100; 

        vector<long long> total_mult(n, 1);
        vector<int> zero_count(n, 0);
        
        vector<vector<vector<long long>>> small_k_mult(B + 1);
        vector<vector<vector<int>>> small_k_zeros(B + 1);

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            long long val = v % MOD;

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    if (val == 0) zero_count[i]++;
                    else total_mult[i] = (total_mult[i] * val) % MOD;
                }
            } else {
                if (small_k_mult[k].empty()) {
                    small_k_mult[k].resize(k);
                    small_k_zeros[k].resize(k);
                }
                int rem = l % k;
                int start_idx = l / k;
                int end_idx = start_idx + (r - l) / k;

                if (small_k_mult[k][rem].empty()) {
                    int size = (n / k) + 2;
                    small_k_mult[k][rem].assign(size, 1);
                    small_k_zeros[k][rem].assign(size, 0);
                }

                if (val == 0) {
                    small_k_zeros[k][rem][start_idx]++;
                    small_k_zeros[k][rem][end_idx + 1]--;
                } else {
                    small_k_mult[k][rem][start_idx] = (small_k_mult[k][rem][start_idx] * val) % MOD;
                    small_k_mult[k][rem][end_idx + 1] = (small_k_mult[k][rem][end_idx + 1] * modInverse(val)) % MOD;
                }
            }
        }

        for (int k = 1; k <= B; ++k) {
            if (small_k_mult[k].empty()) continue;
            for (int rem = 0; rem < k; ++rem) {
                if (small_k_mult[k][rem].empty()) continue;
                long long running_mult = 1;
                int running_zeros = 0;
                for (int i = 0; i < small_k_mult[k][rem].size(); ++i) {
                    running_mult = (running_mult * small_k_mult[k][rem][i]) % MOD;
                    running_zeros += small_k_zeros[k][rem][i];
                    int actual_idx = i * k + rem;
                    if (actual_idx < n) {
                        total_mult[actual_idx] = (total_mult[actual_idx] * running_mult) % MOD;
                        zero_count[actual_idx] += running_zeros;
                    }
                }
            }
        }

        int finalXor = 0;
        for (int i = 0; i < n; ++i) {
            if (zero_count[i] > 0) {
                finalXor ^= 0;
            } else {
                long long final_val = (1LL * (nums[i] % MOD) * total_mult[i]) % MOD;
                finalXor ^= (int)final_val;
            }
        }

        return finalXor;
    }
};