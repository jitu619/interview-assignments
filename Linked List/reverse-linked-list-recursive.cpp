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
    ListNode* headPointer=NULL;
    void reverse(ListNode* head){
        if(head->next==NULL){
            headPointer=head;
            return;
        }
        reverse(head->next);
        ListNode* temp=head->next;
        temp->next=head;
        head->next=NULL;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head)
            reverse(head);
        return headPointer;
    }
};
