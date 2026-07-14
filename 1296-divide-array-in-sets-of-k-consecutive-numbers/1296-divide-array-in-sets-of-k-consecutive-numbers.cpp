class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         priority_queue<int,vector<int>,greater<int>> pq;
        if(nums.size()%k!=0) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
        }
        vector<int> q;
        while(!pq.empty()){
            q.push_back(pq.top());
            pq.pop();
        }
        q.erase(unique(q.begin(),q.end()),q.end());
        priority_queue<int,vector<int>,greater<int>> qp;
        for(int i=0;i<q.size();i++) qp.push(q[i]);
        int cnt=1;
        vector<int> temp;
        while(!qp.empty()){
            int x=qp.top();
            qp.pop();
            temp.push_back(x);
            mp[x]--;
            if(cnt<k){
                if(!qp.empty() && (qp.top()==x || qp.top()==x+1)) cnt++;
                else return false;
            }
            else if(cnt==k){
                cnt=1;
                for(int i=0;i<temp.size();i++) if(mp[temp[i]]>0) qp.push(temp[i]);
                temp.clear();
            }
        }
        return true;
    }
};