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
        ListNode* tp = head;
        ListNode* prev = nullptr;
        if(head == nullptr) return head;
        while(tp->next != nullptr){
            
            if(tp->val == tp->next->val){
                if(prev == nullptr){
                    prev = tp;
                }
                
            }
            else if(prev != nullptr){
                
                prev->next = tp->next;
                prev = nullptr; 
            }
            // cout<<tp->val<<endl;
            // if(prev != nullptr) cout<<prev->val<<" "<<prev->next->val<<endl;
            
            tp = tp->next;
        }
        if(prev != nullptr && prev->val == tp->val) prev->next = nullptr;
        return head; 
    }
};