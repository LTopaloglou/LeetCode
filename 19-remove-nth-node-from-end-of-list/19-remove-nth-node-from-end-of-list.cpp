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
        //Use two pointers; one that goes to the end of the list 
        //and one that goes to the end -n - 1 (since it has to be on the one before to remove)
        
        //go until remove is the first element
        ListNode* last = head;
        for (int i = 0; i < n; i++) {
            last = last->next;
        }
        ListNode* remove = head;
        
        //edge case where n=size
        if (last == NULL) {
            return head->next;
        }
        
        //go until  last hits end of list
        while (true) {
            if (last->next == nullptr) {
                break;
            }
            last = last->next;
            remove = remove->next;
        }
        
        //remove and return head
        remove->next = remove->next->next;
        return head;
    }
    
    
};