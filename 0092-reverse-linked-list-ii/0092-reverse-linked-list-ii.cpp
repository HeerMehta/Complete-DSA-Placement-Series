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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;

        ListNode* curr = head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevToLeft = dummy;
        prevToLeft->next = head;

        ListNode* leftNode;
        ListNode* rightNode;

        int index = 1;

        while(curr && index < right){
            if(index + 1 == left){
                prevToLeft = curr;
            }

            if(index == left){
                leftNode = curr;
            }
            curr = curr->next;
            index++;
        }

        rightNode = curr;

        curr = leftNode;
        ListNode* next = leftNode->next;

        while(next && next != rightNode){
            ListNode* temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
        }

        ListNode* nextToRight = next->next;
        next->next = curr;

        leftNode->next = nextToRight;
        prevToLeft->next = rightNode;


        return dummy->next;
    }
};