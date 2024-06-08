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
        if(!head || !head->next) return NULL;

        ListNode* first = head;

        int i=0;
        while(i<=n){
            if(!first) break;

            first = first->next;
            i++;
        }

        if(n-i == 0){
            head = head->next;
            return head;
        }

        ListNode* second = head;

        while(first){
            first = first->next;
            second = second->next;
        }

        ListNode* nextNode = second->next->next;
        second->next = nextNode;

        return head;

    }
};