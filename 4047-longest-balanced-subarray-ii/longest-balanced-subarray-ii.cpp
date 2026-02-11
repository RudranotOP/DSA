class Solution {
public:
struct SegmentTree {
        int n;
        vector<int> minValue, maxValue, lazyAdd;

        SegmentTree(int size) {
            n = size;
            minValue.assign(4 * n + 5, 0);
            maxValue.assign(4 * n + 5, 0);
            lazyAdd.assign(4 * n + 5, 0);
        }

        void apply(int node, int addValue) {
            minValue[node] += addValue;
            maxValue[node] += addValue;
            lazyAdd[node] += addValue;
        }

        void pushDown(int node) {
            if (lazyAdd[node] != 0) {
                apply(node * 2, lazyAdd[node]);
                apply(node * 2 + 1, lazyAdd[node]);
                lazyAdd[node] = 0;
            }
        }

        void rangeAdd(int node, int left, int right, int queryLeft, int queryRight, int addValue) {
            if (queryRight < left || right < queryLeft) return;
            if (queryLeft <= left && right <= queryRight) {
                apply(node, addValue);
                return;
            }
            pushDown(node);
            int mid = left + (right - left) / 2;
            rangeAdd(node * 2, left, mid, queryLeft, queryRight, addValue);
            rangeAdd(node * 2 + 1, mid + 1, right, queryLeft, queryRight, addValue);
            minValue[node] = min(minValue[node * 2], minValue[node * 2 + 1]);
            maxValue[node] = max(maxValue[node * 2], maxValue[node * 2 + 1]);
        }

        int firstZero(int node, int left, int right, int queryLeft, int queryRight) {
            if (queryRight < left || right < queryLeft) return -1;
            if (minValue[node] > 0 || maxValue[node] < 0) return -1;
            if (left == right) return left;
            pushDown(node);
            int mid = left + (right - left) / 2;
            int leftAnswer = firstZero(node * 2, left, mid, queryLeft, queryRight);
            if (leftAnswer != -1) return leftAnswer;
            return firstZero(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
        }
    };
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        SegmentTree tree(n);

        unordered_map<int, int> lastSeen;
        lastSeen.reserve(n * 2);

        int bestLength = 0;

        for (int r = 0; r < n; r++) {
            int value = nums[r];
            int previousIndex = -1;

            auto it = lastSeen.find(value);
            if (it != lastSeen.end()) previousIndex = it->second;
            lastSeen[value] = r;

            int delta = (value % 2 == 0) ? 1 : -1;

            int leftStart = previousIndex + 2;
            int rightStart = r + 1;

            if (leftStart <= rightStart) {
                tree.rangeAdd(1, 1, n, leftStart, rightStart, delta);
            }

            int earliestStart = tree.firstZero(1, 1, n, 1, r + 1);
            if (earliestStart != -1) {
                bestLength = max(bestLength, (r + 1) - earliestStart + 1);
            }
        }

        return bestLength;
    }
};