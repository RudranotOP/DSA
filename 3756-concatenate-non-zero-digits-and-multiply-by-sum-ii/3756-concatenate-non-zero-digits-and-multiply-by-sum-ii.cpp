class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int MOD = 1e9+7;

        vector<long long> pow10(n+1,1);
        for(int i = 1; i<=n; ++i){
            pow10[i] = (pow10[i-1]*10)%MOD;

        }
        vector<long long> pref_val(n+1, 0);
        vector<int> pref_count(n+1,0);
        vector<long long> pref_sum(n+1, 0);

        for(int i = 0; i<n; ++i){
            int d = s[i]-'0';
            if(d>0){
                pref_val[i+1] = (pref_val[i]*10+d)%MOD;
                pref_count[i+1] = pref_count[i] + 1;
                pref_sum[i+1] = pref_sum[i] + d;
            } else{
                pref_val[i+1] = pref_val[i];
                pref_count[i+1] = pref_count[i];
                pref_sum[i+1] = pref_sum[i];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());

        for(const auto& q: queries){
            int l = q[0];
            int r = q[1];

            int c = pref_count[r+1] - pref_count[l];
            long long sm = pref_sum[r+1] - pref_sum[l];

            long long x = (pref_val[r+1]-(pref_val[l] * pow10[c]) % MOD + MOD) % MOD;

            ans.push_back(static_cast<int>((x * sm) % MOD));
        }
        return ans;
        
    }
};