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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* head=NULL;
        ListNode* last=NULL;
        int s=pq.size();
        for(int i=0;i<s;i++){
            ListNode* temp=new ListNode();
            temp->val=pq.top();
            temp->next=NULL;
            pq.pop();
            if(head==NULL) head=temp;
            else last->next=temp;
            last=temp;
        }
        return head;
    }
};