class Solution {
public:
struct Node {
        long long value;
        int prevIndex;
        int nextIndex;
        bool isActive;
    };

    struct PairTarget {
        long long sum;
        int index;

        bool operator>(const PairTarget& other) const {
            if (sum != other.sum) {
                return sum > other.sum;
            }
            return index > other.index;
        }
    };
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<Node> linkedList(n);
        int unsortedCount = 0;

        for (int i = 0; i < n; ++i) {
            linkedList[i].value = nums[i];
            linkedList[i].prevIndex = i - 1;
            linkedList[i].nextIndex = (i + 1 < n) ? i + 1 : -1;
            linkedList[i].isActive = true;

            if (i + 1 < n && nums[i] > nums[i + 1]) {
                unsortedCount++;
            }
        }

        if (unsortedCount == 0) return 0;

        priority_queue<PairTarget, vector<PairTarget>, greater<PairTarget>> minHeap;

        for (int i = 0; i < n - 1; ++i) {
            long long currentSum = (long long)nums[i] + nums[i + 1];
            minHeap.push({currentSum, i});
        }

        int operations = 0;

        while (unsortedCount > 0 && !minHeap.empty()) {
            PairTarget currentPair = minHeap.top();
            minHeap.pop();

            int leftIdx = currentPair.index;

            if (!linkedList[leftIdx].isActive) continue;

            int rightIdx = linkedList[leftIdx].nextIndex;
            if (rightIdx == -1) continue;

            long long actualSum = linkedList[leftIdx].value + linkedList[rightIdx].value;
            if (actualSum != currentPair.sum) continue;

            operations++;

            int prevIdx = linkedList[leftIdx].prevIndex;
            int nextIdx = linkedList[rightIdx].nextIndex;

            if (prevIdx != -1 && linkedList[prevIdx].value > linkedList[leftIdx].value) {
                unsortedCount--;
            }
            if (linkedList[leftIdx].value > linkedList[rightIdx].value) {
                unsortedCount--;
            }
            if (nextIdx != -1 && linkedList[rightIdx].value > linkedList[nextIdx].value) {
                unsortedCount--;
            }

            linkedList[leftIdx].value = actualSum;
            linkedList[leftIdx].nextIndex = nextIdx;
            linkedList[rightIdx].isActive = false;

            if (nextIdx != -1) {
                linkedList[nextIdx].prevIndex = leftIdx;
            }

            if (prevIdx != -1) {
                if (linkedList[prevIdx].value > linkedList[leftIdx].value) {
                    unsortedCount++;
                }
                long long newLeftSum = linkedList[prevIdx].value + linkedList[leftIdx].value;
                minHeap.push({newLeftSum, prevIdx});
            }

            if (nextIdx != -1) {
                if (linkedList[leftIdx].value > linkedList[nextIdx].value) {
                    unsortedCount++;
                }
                long long newRightSum = linkedList[leftIdx].value + linkedList[nextIdx].value;
                minHeap.push({newRightSum, leftIdx});
            }
        }

        return operations;
    }
};