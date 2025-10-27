/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *res = headA;

        while(res != nullptr){
            ListNode *t = headB;
            while(t != nullptr){
                if(t == res ){
                    return t;
                }
                t = t->next;
            }
            res = res->next;
        }
        return res;
    }
};
