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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1==NULL && list2==NULL) return NULL;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* dNode=new ListNode(-1);
        ListNode* temp=dNode;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1) temp->next=temp1;
        else temp->next=temp2;
        return dNode->next;
        
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findMiddle(head); 
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);

        return mergeTwoLists(lefthead,righthead);

    }
};