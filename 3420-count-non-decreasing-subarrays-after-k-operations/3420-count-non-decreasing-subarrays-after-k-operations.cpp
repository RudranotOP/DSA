class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long answer = 0;
        long long cost = 0;

        int right = n - 1;

        deque<pair<int, int>> dq;

        for(int left = n - 1; left >= 0; left--){
            int current = nums[left];
            int count = 1;
            while(!dq.empty() && dq.back().first<current){
                int height = dq.back().first;
                int groupSize = dq.back().second;
                dq.pop_back();
                count += groupSize;
                cost += 1LL*(current-height)*groupSize;
            }
            dq.push_back({current, count});
            while(cost>k){
                int height = dq.front().first;
                int groupSize = dq.front().second;
                dq.pop_front();
                cost-=height - nums[right];
                right--;
                if(groupSize>1){
                    dq.push_front({height, groupSize-1});
                }
            }
            answer += right-left+1;
        }
        return answer;
        
    }
};