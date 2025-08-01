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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* tp = head;
        while(tp != nullptr){
            n++;
            tp = tp->next;
        }
        // cout<<n<<endl;
        // cout<<(n/2)-1<<endl;
        tp = head;
        ListNode* tp1 = nullptr;
        n = n/2 -1;
        while(n>0){
            tp = tp->next;
            n--;
        }
        tp1 = tp->next;
        
        //need to reverse later half of the list
        ListNode* temp = tp1;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* t = temp->next;
            temp->next = prev;
            prev = temp;
            temp = t; 
        }
        tp->next = prev;
        tp1 = prev;
        tp = head;
        int max = tp->val + tp1->val;
        tp = tp->next;
        tp1 = tp1->next;
        while(tp1 != nullptr){
            if((tp->val + tp1->val) > max) max = tp->val + tp1->val;
            tp = tp->next;
            tp1 = tp1->next;
        }
        return max;
    }
};