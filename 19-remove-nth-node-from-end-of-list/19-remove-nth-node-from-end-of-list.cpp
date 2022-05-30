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
        if (n==1 && head->next == nullptr) {
            return head->next;
        }
        if (remove(head, n, true) == -999) {
            return head->next;
        }
        return head;
    }
    
    int remove (ListNode* current, int a, bool first) {
        //keep calling with a, returning with a-1
        
        //if node is not terminal, call again with a
        int temp;
        if (current->next != nullptr) {
            temp = remove(current->next, a, false);
            //if return value is 1 and first is true, return -2 to indicate that head->next should be returned
            if (temp == 1 && first) {
                return -999;
            }
            // if temp = 0, remove next node
            if (temp == 0) {
                current->next = current->next->next;
            }
            //return temp-1 
            return temp-1;
        }
        return a-1;
    }
    
    
};