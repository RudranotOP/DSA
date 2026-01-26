class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int minDiff = 2000000; 
        
        for(int i = 0; i < n - 1; i++) {
            int currentDiff = arr[i+1] - arr[i];
            if(currentDiff < minDiff) {
                minDiff = currentDiff;
            }
        }

        vector<vector<int>> result;

        for(int i = 0; i < n - 1; i++) {
            if(arr[i+1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i+1]});
            }
        }

        return result;
    }
};