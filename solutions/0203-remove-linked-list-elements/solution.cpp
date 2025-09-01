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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1,head);
        ListNode *t = head , *prev = NULL;

        while(t != NULL){
            if(t->val == val){
                if(t == head){
                    dummy->next = t->next;
                    prev = dummy; 
                }
                prev->next = t->next;
                t = t->next;
            }
           else{
                prev = t;
                t = t->next;
           }
        }
        return dummy->next;

    }
};
