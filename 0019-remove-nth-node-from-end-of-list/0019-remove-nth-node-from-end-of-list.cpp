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
    int size(ListNode* head){
        int count =1;
        while(head->next != nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int siz = size(head);
        if(siz == n) return head->next;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        for(int i=0 ; i<siz-n-1 ; i++){
            temp1=temp1->next;
        }
        for(int i=0 ; i<siz-n+1 ; i++){
            temp2=temp2->next;
        }
        temp1->next = temp2;
        return head;
    }
};