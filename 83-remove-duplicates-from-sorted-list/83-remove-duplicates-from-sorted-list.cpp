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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        
        unordered_set<int> seen;
        seen.insert(head -> val);
        ListNode* previous = head;
        ListNode* current = head -> next;
        
        while (current) {
            if (seen.count(current -> val)) {
                current = current -> next;
            } else {
                seen.insert(current -> val);
                previous -> next = current;
                previous = current;
                current = current -> next;
            }
        }
        
        previous -> next = NULL;
        
        return head;
    }
};