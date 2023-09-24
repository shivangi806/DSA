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
    ListNode* middleNode(ListNode* head) {
        int c=0;
        ListNode* temp = head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        // if(c%2==0){
        //     c=c/2-1;
        // }
        // else{
        //     c=c/2;
        // }
        c=c/2;
        int i=0;
        temp=head;
        while(i<c){
            i++;
            temp=temp->next;
        }
        return temp;
    }
};