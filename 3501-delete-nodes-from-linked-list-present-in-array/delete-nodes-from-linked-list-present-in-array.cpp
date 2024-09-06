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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto &x:nums){
            st.insert(x);
        }
        while((st.contains(head->val))){
            head = head->next;
            
        }
        ListNode* prev = head;
        ListNode* temp = head;
        while(temp){
            if(st.contains(temp->val)){
                ListNode* td = temp;
                while( temp and st.contains(temp->val)  ){
                        temp = temp->next;
                }
                prev->next = temp;
                prev =temp;
            }
            prev =temp;
            if(temp)
            temp = temp->next;
        }
        return head;
    }
};