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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = head;
        int count = 0;

        if(head == NULL || head->next == NULL){ 
            return NULL;
        }

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int pos = count - n + 1;
        temp = head;

        if(pos == 1){
            return head->next;
        }
        for(int i = 1 ; i < pos ; i++ ){
            prev = temp;
            temp = temp->next;
        }

        if(pos == count){
            prev->next = nullptr;
        }
        else{
            prev->next = temp->next;
        }
        
        return head;
    }
};
