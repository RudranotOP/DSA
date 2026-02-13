class Solution {
     static unsigned long long makeKey(int x, int y) {
        unsigned long long high = (unsigned long long)(unsigned int)x;
        unsigned long long low  = (unsigned long long)(unsigned int)y;
        return (high << 32) | low;
    }

    int bestSingleRun(const string& s) {
        int best = 0, current = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) current++;
            else current = 1;
            if (current > best) best = current;
        }
        return best;
    }

    int bestTwoLettersBlocking(const string& s, char blocked) {
        int n = (int)s.size();
        int offset = n + 2;

        vector<int> firstIndex(2 * n + 5, 0);
        vector<int> stampSeen(2 * n + 5, 0);
        int stamp = 1;

        int best = 0;
        int balance = 0;

        stampSeen[offset] = stamp;
        firstIndex[offset] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == blocked) {
                stamp++;
                balance = 0;
                stampSeen[offset] = stamp;
                firstIndex[offset] = i;
                continue;
            }

            if (blocked == 'a') balance += (s[i] == 'b') ? 1 : -1;
            else if (blocked == 'b') balance += (s[i] == 'a') ? 1 : -1;
            else balance += (s[i] == 'a') ? 1 : -1;

            int idx = balance + offset;

            if (stampSeen[idx] == stamp) {
                int length = i - firstIndex[idx];
                if (length > best) best = length;
            } else {
                stampSeen[idx] = stamp;
                firstIndex[idx] = i;
            }
        }

        return best;
    }

    int bestThreeLetters(const string& s) {
        int n = (int)s.size();
        unordered_map<unsigned long long, int> firstSeen;
        firstSeen.reserve(n * 2);
        firstSeen.max_load_factor(0.7f);

        int countA = 0, countB = 0, countC = 0;
        int best = 0;

        firstSeen[makeKey(0, 0)] = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            unsigned long long key = makeKey(diffAB, diffAC);

            auto it = firstSeen.find(key);
            if (it != firstSeen.end()) {
                int length = (i + 1) - it->second;
                if (length > best) best = length;
            } else {
                firstSeen[key] = i + 1;
            }
        }

        return best;
    }

public:
    int longestBalanced(string s) {
        int best = 0;
        best = max(best, bestSingleRun(s));
        best = max(best, bestTwoLettersBlocking(s, 'a'));
        best = max(best, bestTwoLettersBlocking(s, 'b'));
        best = max(best, bestTwoLettersBlocking(s, 'c'));
        best = max(best, bestThreeLetters(s));
        return best;
    }
};