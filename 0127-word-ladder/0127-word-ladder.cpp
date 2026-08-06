class Solution {
public:
    int count=0;
    void words(string s,unordered_map<string,int>& mp,unordered_map<string,bool>& visited,queue<pair<string,int>>& q,int level){
        for(int i=0;i<s.size();i++){
            string temp=s;
            for(int j=97;j<=122;j++){
                temp[i]=j;
                if(mp[temp]>0 && !visited[temp]){
                    visited[temp]=true;
                    q.push({temp,level+1});
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> visited;
        unordered_map<string,int> mp;
        queue<pair<string,int>> q;
        mp[beginWord]++;
        for(int i=0;i<wordList.size();i++) mp[wordList[i]]++;
        q.push({beginWord,1});
        while(!q.empty()){
            pair<string,int> temp=q.front();
            q.pop();
            if(temp.first==endWord) return temp.second;
            words(temp.first,mp,visited,q,temp.second);
        }
        return 0;
    }
};