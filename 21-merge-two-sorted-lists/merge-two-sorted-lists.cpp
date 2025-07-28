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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tp1 = list1;
        ListNode* tp2 = list2;
        ListNode* prev = nullptr;
        bool f = true;
        if(tp1 == nullptr) return list2;
        if(tp2 == nullptr) return list1;
        if(list1->val <= list2->val){
            while(tp1 != nullptr && tp2 != nullptr){
                
                if(tp1->val == tp2->val){
                    prev = tp1;
                    tp1 = tp1->next;
                    tp2 = list2;
                    continue;
                }
                if(tp1->val > tp2->val){
                    list2 = tp2->next;
                    prev->next = tp2;
                    tp2->next = tp1;
                    prev = tp2;
                    tp2 = list2;
                    continue;
                }
                prev = tp1;
                tp1 = tp1->next;
                tp2 = list2;    
            }
            
        }
        else{
            f = false;
            while(tp1!=nullptr && tp2 != nullptr){
                
                if(tp1->val == tp2->val){
                    prev = tp2;
                    tp2 = tp2->next;
                    tp1 = list1;
                    continue;
                }
                if(tp2->val > tp1->val){
                    list1 = tp1->next;
                    prev->next = tp1;
                    tp1->next = tp2;
                    prev = tp1;
                    tp1 = list1;
                    continue;
                }
                prev = tp2;
                tp2 = tp2->next; 
                tp1 = list1;   
            }
        }
        if(f){
           // cout<<list2->val;
            tp2 = list2;
            while(tp2 != nullptr){
                prev->next = tp2;
                prev = prev->next;
                tp2 = tp2->next; 
            }
            return list1;
        }
        tp1 = list1;
            while(tp1 != nullptr){
                prev->next = tp1;
                prev = prev->next;
                tp1 = tp1->next; 
            }
        return list2;
        }
        
    
};