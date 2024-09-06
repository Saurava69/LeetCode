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
        // Create an unordered set to store the elements from the vector 'nums'
        unordered_set<int> st;
        for (auto &x : nums) {
            st.insert(x);
        }
        
        // Remove nodes from the beginning of the list if they are present in the set
        while (head && st.contains(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete temp;  // Free the memory of the removed node
        }
        
        // If the head becomes null (i.e., all nodes were removed), return null
        if (!head) return nullptr;
        
        // Initialize pointers to traverse the list
        ListNode* prev = head;  // 'prev' will keep track of the last valid node
        ListNode* temp = head;  // 'temp' is used to traverse the list
        
        while (temp) {
            // If the current node's value is in the set, skip all consecutive nodes that are also in the set
            if (st.contains(temp->val)) {
                while (temp && st.contains(temp->val)) {
                    ListNode* toDelete = temp;  // Node to be deleted
                    temp = temp->next;  // Move 'temp' to the next node
                    delete toDelete;  // Free the memory of the removed node
                }
                prev->next = temp;  // Link 'prev' to the first node after the sequence of nodes to be removed
            }
            // Move 'prev' to 'temp' only if 'temp' is not null
            prev = temp;
            if (temp) temp = temp->next;  // Move 'temp' to the next node in the list
        }
        
        return head;  // Return the modified head of the list
    }
};
