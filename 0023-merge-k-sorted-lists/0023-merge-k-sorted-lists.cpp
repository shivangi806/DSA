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
    
    // void convertVectToLinkList(ListNode* head , int value){
    //     ListNode* temp = new ListNode;
    //     temp->val = value;
    //     temp->next = NULL ;
    //     if(head==NULL) head = new ListNode ;
    //     else{
    //         ListNode* rt= head;
    //         while(rt->next!=NULL) rt=rt->next;
    //         rt->next = new ListNode ;
    //     }
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       vector<int> ans;
        for(int i=0;i<lists.size();i++){
           ListNode* head = lists[i];
           while(head!=NULL){
               ans.push_back(head->val);
               head=head->next;
           }
       }
        sort(ans.begin(),ans.end(),greater<int>());
        ListNode*  head = NULL ;
        for(int i=0;i<ans.size();i++){
            head = new ListNode(ans[i] , head);
        }
        return head;
    }
};