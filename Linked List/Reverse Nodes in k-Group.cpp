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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        int count=0;
        ListNode* temp =head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        int value = count/k;
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* nex = temp->next;
        ListNode*head1;
        int flag=0;
        while(value!=0){
             for(int i=0;i<k && curr!=NULL;i++){
                 if(i==0) head1=curr;
                 curr->next = prev;
                 prev = curr;
                 curr = nex;
                 if(nex!=NULL)
                 nex=nex->next;
                }
            if(flag==0){
                flag=1;
                head=prev;
                temp=head1;
            }else{
                temp->next=prev;
                temp=head1;
            }
            value--;
        }
        if(curr==NULL)temp->next=NULL;
        else temp->next=curr;
        return head;
    }
};
