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
        ListNode* tp = head;
        ListNode* prev = nullptr;
        while(tp != nullptr){
            ListNode* temp = tp->next;
            tp->next = prev;
            prev = tp;
            tp = temp;
        }
        
        return prev;
    }
};