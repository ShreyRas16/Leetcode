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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL) return{-1,-1};
        if(head->next->next==NULL) return {-1,-1};
        ListNode* temp=head;
        ListNode* temp1=head->next;
        ListNode* temp2=head->next->next;
        int first=-1;
        int last=-1;
        int curr1=0;
        int curr2=0;
        int minidist=INT_MAX;
        int count=0;
        while(temp2!=NULL){
            count++;
            if((temp1->val > temp->val && temp1->val > temp2->val) || (temp1->val < temp->val && temp1->val < temp2->val)){
                if(first==-1) first=count;
                last=count;
                if(curr1==0) curr1=count;
                else{
                    curr2=curr1;
                    curr1=count;
                    minidist=min(minidist,curr1-curr2);
                }
            }
            temp=temp1;
            temp1=temp2;
            temp2=temp2->next;
        }
        if(first==last) return {-1,-1};
        return {minidist,last-first};
    }
};