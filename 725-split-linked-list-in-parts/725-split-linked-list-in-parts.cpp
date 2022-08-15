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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> output(k);
        
        //find length of linked lis
        int len = 0;
        if (head == nullptr) {
            //special case linked list is empty
            return output;
        }
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr= curr->next;
        }
        
        cout << len << " is the length, " << k << " is the divisions" << endl;
        //now find nodes per division
        int nodes = (len + k -1) / k;
        cout << nodes << " is the # of nodes per division" << endl;
        //and which will have node n-1
        int less = len % k;
        if (less == 0) {
            less = k;
        }
        cout << "after index " << less << " the divisions have 1 less" << endl;
        
        //now get to splitting up list
        curr = head;
        ListNode* Next = head->next;
        for (int i = 0; i < k; i++) {
            cout << "got here" << endl;
            int currNodes = nodes;
            if (i >= less) {
                currNodes--;
            }
            output[i] = curr;   
            for (int i = 0; i < currNodes-1; i++) {
                cout << curr->val << "->";
                curr = Next;
                if (curr != nullptr) {
                    Next = curr->next;
                }
            }
            //cut
            if (curr!= nullptr) {
                curr->next = nullptr;
            }
            curr = Next;
            if (Next != nullptr) {
                Next = curr->next;
            }
            cout << endl;
        }
        return output;
    }
};