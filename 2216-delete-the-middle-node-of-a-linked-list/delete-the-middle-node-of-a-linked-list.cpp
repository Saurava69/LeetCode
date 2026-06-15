class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        if(!head->next) return NULL;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = head;
        while(temp->next!=NULL && temp->next != slow){
            temp = temp->next;
        }
        if(slow) temp->next = slow->next;
        delete slow;
        return head;
    }
};