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
        //only two nodes
        if(head->next->next==nullptr){
            return head->val+head->next->val;
        }
        stack<int>st;
        int res =0;
        ListNode* p=head; // slow
        ListNode* q=head; // fast
        while(q != nullptr){
            st.push(p->val);
            p=p->next;
            q=q->next->next;
        }
        while(p != nullptr || !st.empty()){
            if((st.top()+p->val)>res){
                res=st.top()+p->val;
            }
            p=p->next;
            st.pop();
        }
        return res;
    }
};