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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int max = -1;
        for(auto n : nums){
            if(n > max) max = n;
        }
        vector<bool> present(max+1,true);
        for(auto i : nums){
            present[i] = false;
        }

        ListNode* d = new ListNode();
        ListNode* c = d;
        //ListNode* p = nullptr;
        while(head != nullptr){
            if(present.size() <= head->val || present[head->val]){
                //cout<<head->val<<" "<<present[head->val]<<endl;
                c->next = head;
                c = c->next;
                //p = c;
            }

            head = head->next;
        }
        c->next = nullptr;
        //if(c!= nullptr && !present[c->val]) p->next = nullptr;
        d = d->next;
        return d;
    }
};