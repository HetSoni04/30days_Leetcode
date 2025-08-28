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
        if(head == nullptr) return false;
        set<ListNode*> s;
        ListNode* tp = head;
        
        while(tp->next != nullptr || s.find(tp) != s.end()){
            if(s.find(tp->next) != s.end()){
                return true;
            }
            s.insert(tp);
            tp =tp->next;
        }
        return false;
     }
};