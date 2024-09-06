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
        unordered_set<int>set(begin(nums),end(nums)); // insert
        
        // Handel the Head
        while(head != NULL && set.find(head->val) != set.end()){
            ListNode* temp = head ;
            head=head->next;
            delete(temp);
        }
        
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            if(set.find(curr->next->val)!=set.end()){
                ListNode* temp = curr->next;
                curr->next = curr->next->next; // curr->next is updated
                delete(temp);
            } else{
                curr = curr->next;
            }
        }
        return head;
    }
};