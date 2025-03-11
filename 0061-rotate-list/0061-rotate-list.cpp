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
    int length(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len=length(head);
        k=k%len;
        if(k%len==0) return head;
        ListNode* temp=head;
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        int ans=len-k;
        while(ans>1){
            temp=temp->next;
            ans--;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }
};