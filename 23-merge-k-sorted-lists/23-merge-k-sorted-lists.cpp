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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists.front();
        
        ListNode* merged = lists.front();
        lists.erase(lists.begin());
        for (auto& list : lists) {
            merged = merge(merged, list);
        }
        
        return merged;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* previous = head;
        
        while (list1 && list2) {
            if (list1 -> val < list2 -> val) {
                previous -> next = list1;
                previous = list1;
                list1 = list1 -> next;
            } else {
                previous -> next = list2;
                previous = list2;
                list2 = list2 -> next;
            }
        }
        
        if (list1) previous -> next = list1;
        else previous -> next = list2;
        
        return head -> next;
    }
};