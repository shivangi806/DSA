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
    ListNode* temp;
    vector<int> v ;
    Solution(ListNode* head) {
       temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() {
       
        int mod = v.size() ;
        return v[rand()%mod] ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */