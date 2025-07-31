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
    //ListNode* removeNodes(ListNode* head) {
        // ListNode* tp = head;
        // ListNode* prev = nullptr;
        // if(head == nullptr) return head;
        // while(tp->next != nullptr){
        //     if(tp->val < tp->next->val){
        //         if(tp == head){
        //             head = tp->next;
        //         } 
        //         else{
        //             prev->next = tp->next;
        //             tp = prev;
        //             continue;
        //         } 
        //     }
        //     prev = tp;
        //     tp = tp->next;
        // }
        // return head;
//}
    ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    head = reverse(head);

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    int maxSoFar = INT_MIN;

    while (head) {
        if (head->val >= maxSoFar) {
            maxSoFar = head->val;
            curr->next = head;
            curr = curr->next;
        }
        head = head->next;
    }
    curr->next = nullptr;

    return reverse(dummy->next);
}

    
};