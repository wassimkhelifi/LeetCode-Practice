/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        unordered_set<ListNode*> visited;
        ListNode* current = head;
        while (current) {
            if (visited.count(current)) return true;
            visited.insert(current);
            current = current -> next;
        }
        
        return false;
    }
};