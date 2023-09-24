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

    ListNode* findmid(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return temp ;
    }

    ListNode* merge(ListNode* p1 , ListNode* p2){
        if(p1==NULL) return p2;
        if(p2==NULL) return p1;

        ListNode* temp = new ListNode(0);
        ListNode * tt = temp;
        while(p1!=NULL && p2!=NULL){
            if(p1->val <= p2->val){
                tt->next = p1;
                p1=p1->next;
            }
            else{
                tt->next = p2;
                p2=p2->next;
            }
            tt=tt->next;
        }
        if(p1!=NULL){
            tt->next= p1;
            p1=p1->next;
        }
        if(p2!=NULL){
            tt->next= p2;
            p2=p2->next;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = findmid(head);
        ListNode* newhead = mid->next;
        mid->next=NULL;
        ListNode* lh = sortList(head);
        ListNode* rh = sortList(newhead);
        return merge(lh,rh);
    }
};