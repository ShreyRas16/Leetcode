class Solution {
public:
    class dist{
        vector<int> parent;
        public:
        dist(int n){
            parent.resize(n);
            for(int i=0;i<parent.size();i++){
                parent[i]=i;
            }
        }
        int find(int n){
            if(parent[n]==n) return n;
            return parent[n]=find(parent[n]);
        }
        void uni(int i,int j){
            int pi=find(i);
            int pj=find(j);
            if(pi!=pj) parent[pj]=pi;
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        dist ds(accounts.size());
        unordered_map<string,bool> seen;
        unordered_map<string,int> count;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(!count.count(accounts[i][j])){
                count[accounts[i][j]]=i;
                }
            }
        }
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(seen[accounts[i][j]]){
                    ds.uni(i,count[accounts[i][j]]);
                }
                else seen[accounts[i][j]]=true;
            }
        }
        unordered_map<int,int> freq;
        for(int i=0;i<accounts.size();i++){
            freq[ds.find(i)]++;
        }
        int un=freq.size();
        unordered_map<int,int> renu;
        for(int i=0;i<accounts.size();i++){
            int r=ds.find(i);
            if(!renu.count(r)) renu[r]=renu.size();
        }
        vector<vector<string>> ans(un);
        unordered_map<int,bool> check;
        for(int i=0;i<accounts.size();i++){
            int slot=renu[ds.find(i)];
            if(!check[ds.find(i)]){
                ans[slot].push_back(accounts[ds.find(i)][0]);
                check[ds.find(i)]=true;
            }
            for(int j=1;j<accounts[i].size();j++){
                ans[slot].push_back(accounts[i][j]);
            }
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin()+1,ans[i].end());
            ans[i].erase(unique(ans[i].begin()+1,ans[i].end()),ans[i].end());
        }
        return ans;
    }
};