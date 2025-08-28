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
    ListNode *detectCycle(ListNode *head) {
        // if(head == nullptr) return nullptr;
        // if(head->next == nullptr) return nullptr;
        // if(head->next->next == nullptr) return nullptr;
        // if(head->next->next == head) return head->next->next;
        // ListNode* fast = head;
        // ListNode* slow = head;
        // while(fast != nullptr && fast->next != nullptr){
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if(fast == slow) return slow;
        // }
        // return nullptr;

        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr;
        if(head->next->next == nullptr) return nullptr;
        if(head->next->next == head) return head->next->next;
        set<ListNode*> s;
        ListNode* tp = head;
        
        while(tp->next != nullptr || s.find(tp) != s.end()){
            if(s.find(tp->next) != s.end()){
                return tp->next;
            }
            s.insert(tp);
            tp =tp->next;
        }
        return nullptr;
    }
};