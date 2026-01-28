/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummyValue = new ListNode(0);
        dummyValue->next = head;

        ListNode* prevNode = dummyValue;

        for (int i = 0; i < left - 1; i++) {
            prevNode = prevNode->next;
        }

        ListNode* currentNode = prevNode->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = nextNode->next;
            nextNode->next = prevNode->next;
            prevNode->next = nextNode;
        }

        return dummyValue->next;
    }
};