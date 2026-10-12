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
    bool isPalindrome(ListNode* head) {
        vector<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push_back(temp->val);
            temp=temp->next;
        }
         temp=head;
        for(int i=st.size()-1;i>=0;i--){
            if(temp->val != st[i]){
                return false;
            }
            temp=temp->next;
        }
            
        
    return true;
    }
};