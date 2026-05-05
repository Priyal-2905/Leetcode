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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        
        for(ListNode *i = head;i != NULL;i = i->next){ len++;}

        if(len == 0||len == 1||k==0){
            return head;
        }

        k = k%len;
        int n = len-k;

        ListNode *curr = head;
        ListNode *prev = head;
        for(int i = 1;i <= n;i++){
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            return head;
        }

        prev->next = NULL;
        ListNode *h1 = curr;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;
        return h1;
        
    }
};
