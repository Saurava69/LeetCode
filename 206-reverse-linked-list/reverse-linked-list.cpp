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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev=NULL,*NextPtr=NULL;
    //     while(head)
    //     {
    //         NextPtr=head->next;
    //         head->next=prev;
    //         prev=head;
    //         head=NextPtr;
    //     }
    //     return prev;
    // }
    ListNode* reverseList(ListNode* head) {
    if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}
};