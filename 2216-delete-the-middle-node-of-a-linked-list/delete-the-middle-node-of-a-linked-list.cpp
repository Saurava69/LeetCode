class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head, *slow = head;

        if (fast->next == NULL) return NULL;
        fast = fast->next->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};