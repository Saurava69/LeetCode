class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);

        int ans = 0;
        ListNode* first = head;

        while(slow) {
            ans = max(ans, first->val + slow->val);
            first = first->next;
            slow = slow->next;
        }

        return ans;
    }
};