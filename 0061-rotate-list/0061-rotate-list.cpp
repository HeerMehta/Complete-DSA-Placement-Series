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
        if(!head || !head->next || k == 0){
            return head;
        }

        int size = 0;

        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            size++;
        }

        int n = k%size;

        if(n == 0) return head;

        curr = head;

        while(curr->next){
            curr = curr->next;
        }

        curr->next = head;

        ListNode* newTail = head;

        for(int i=0; i<size-n-1; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;


    }
};