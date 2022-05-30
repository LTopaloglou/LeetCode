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
        //traverse the list to left, then do a regular reversal for (right-left)+1 elements
        //make sure that the element before the reversal points to the tail of the sublist
        //and the element after the reversal is pointed to by the last of the sublist
        ListNode* before = head;
        //if before has to be reversed (left = 1)
        if (left == 1) {
            return reverseList(before, right-left);
        }
        //makes before the element before the reversal.
        for (int i = 1; i < left-1; i++) {
            before = before->next;
        }
        //reverse the element
        before->next = reverseList(before->next, right-left);
        return head;
    }
    
    ListNode* reverseList(ListNode* head, int elements) {
        //edge case size =1 or size =0
        if (elements == 0) {
            return head;
        }
        ListNode* current = head;
        ListNode* next = head->next;
        ListNode* temp;
        //turn head into tail 
        current->next = nullptr;
        for (int i = 0; i < elements; i++) {
            temp = next->next;
            next->next = current;
            current = next;
            next = temp;
        }
        head->next = temp;
        return current;
    }
};