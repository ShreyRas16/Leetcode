class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<pair<int,int>> p;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) count[nums[i]]++;
        for(auto &x:count) p.push_back({x.second,x.first});
        for(int i=0;i<p.size();i++){
            if(pq.size()<k) pq.push(p[i]);
            else{
                if(p[i]>pq.top()){
                    pq.pop();
                    pq.push(p[i]);
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};