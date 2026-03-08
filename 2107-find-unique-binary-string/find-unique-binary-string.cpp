class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string answer = "";

        for (int index = 0; index < n; index++) {
            if (nums[index][index] == '0') answer.push_back('1');
            else answer.push_back('0');
        }

        return answer;
    }
};