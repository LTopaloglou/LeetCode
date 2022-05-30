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
    ListNode* reverseList(ListNode* head) {
        //edge case size =1 or size =0
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* current = head;
        ListNode* next = head->next;
        ListNode* temp;
        //turn head into tail 
        current->next = nullptr;
        while (true) {
            temp = next->next;
            next->next = current;
            current = next;
            next = temp;
            if (temp == nullptr) {
                break;
            }
        }
        return current;
    }
};