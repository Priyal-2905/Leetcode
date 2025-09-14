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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode();
        ListNode *h2 = new ListNode();

        ListNode *t1 = h1;
        ListNode *t2 = h2;

        ListNode *t = head;

        while(t != NULL){
            if(t->val < x){
                t1->next = t;
                t1 = t1->next;
            }
            else{
                t2->next = t;
                t2 = t2->next;
            }
            t = t->next;
        }
        t2->next = NULL;
        t1->next = h2->next;

        return h1->next;
    }
};
