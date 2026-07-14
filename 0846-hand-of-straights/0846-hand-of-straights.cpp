class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>> pq;
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            pq.push(hand[i]);
            mp[hand[i]]++;
        }
        vector<int> q;
        while(!pq.empty()){
            q.push_back(pq.top());
            pq.pop();
        }
        q.erase(unique(q.begin(),q.end()),q.end());
        priority_queue<int,vector<int>,greater<int>> qp;
        for(int i=0;i<q.size();i++) qp.push(q[i]);
        int k=1;
        vector<int> temp;
        while(!qp.empty()){
            int x=qp.top();
            qp.pop();
            temp.push_back(x);
            mp[x]--;
            if(k<groupSize){
                if(qp.top()==x || qp.top()==x+1) k++;
                else return false;
            }
            else if(k==groupSize){
                k=1;
                for(int i=0;i<temp.size();i++) if(mp[temp[i]]>0) qp.push(temp[i]);
                temp.clear();
            }
        }
        return true;
    }
};