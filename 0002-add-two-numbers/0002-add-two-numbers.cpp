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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        
        int sum=0;
        int carry=0;
        if(temp1) sum+=temp1->val;
        if(temp2) sum+=temp2->val;

        ListNode* startNode=new ListNode(sum%10);
        ListNode* head=startNode;
        ListNode* curr=startNode;
        carry=sum/10;
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
        while(temp1!=NULL || temp2!=NULL){
            sum=0;
            if(carry>0) sum+=carry;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;

            ListNode* newNode=new ListNode(sum%10);
            curr->next=newNode;
            curr=newNode;
            carry=sum/10;

            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;

        } 
        if(carry){ 
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
            curr=curr->next;
            
        }
        return head;  
    }
};