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
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        
        int size = 0;
        ListNode* current = head;
        while (current) {
            size++;
            current = current -> next;
        }
        
        int middle = size / 2;
        current = head;
        int count = 0;
        while (count < middle) {
            count++;
            current = current -> next;
        }
        
        return current;
    }
};