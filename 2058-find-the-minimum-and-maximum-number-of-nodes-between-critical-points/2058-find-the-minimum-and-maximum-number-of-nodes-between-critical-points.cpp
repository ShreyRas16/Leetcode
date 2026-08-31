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
        ListNode* temp=head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        if(arr.size()<3) return {-1,-1};
        vector<int> other;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) other.push_back(i);
            else if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) other.push_back(i);   
        }
        if(other.size()==0 || other.size()==1) return {-1,-1};
        int minidist=INT_MAX;
        for(int i=1;i<other.size();i++){
            minidist=min(minidist,other[i]-other[i-1]);
        }
        return {minidist,other[other.size()-1]-other[0]};
    }
};