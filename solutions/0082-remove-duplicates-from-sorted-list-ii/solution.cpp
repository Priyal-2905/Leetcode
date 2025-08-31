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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL){return NULL;}

    ListNode *dummy = new ListNode();  
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* t = head;

    while (t != NULL) {
        bool duplicate = false;

        while (t->next != NULL && t->val == t->next->val) {
            duplicate = true;
            t = t->next;
        }

        if (duplicate) {
            prev->next = t->next;
        } else {
            prev = prev->next;
        }

        t = t->next;
    }

    return dummy->next;
}
};
