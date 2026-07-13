class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        priority_queue<int> pq;
        int sum=0;
        int maxno=1;
        for(int i=0;i<tasks.size();i++) count[tasks[i]]++;
        for(int i=65;i<91;i++){
            if(count[i]!=0){
               pq.push(count[i]);
               sum=sum+count[i];
            }
        }
        int s=pq.size();
        int x=pq.top();
        for(int i=0;i<s;i++){
            pq.pop();
            if(!pq.empty() && pq.top()==x) maxno++;
            else break;
        }
        int rest=0;
        while(!pq.empty()){
            rest=rest+pq.top();
            pq.pop();
        }
        int restn=n-maxno+1;
        int need=restn*(x-1);
        int toad=need-rest;
        if(toad>0) sum=sum+toad;
        return sum;
    }
};