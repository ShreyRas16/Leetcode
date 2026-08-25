class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,bool> present;
        vector<pair<int,int>> nodes;
        unordered_map<char,pair<int,int>> info;
        for(int i=0;i<s.size();i++){
            present[s[i]]=true;
        }
        for(char c='a';c<='z';c++){
            if(present[c]){
                int first=0;
                int last=s.size();
                for(int i=0;i<s.size();i++){
                    if(s[i]==c){
                        first=i;
                        break;
                    }
                }
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]==c){
                        last=i;
                        break;
                    }
                }
                nodes.push_back({first,last});
                info[c].first=first;
                info[c].second=last;
            }
        }
        sort(nodes.begin(),nodes.end());
        vector<pair<int,int>> final;
        final.push_back(nodes[0]);
        for(int i=1;i<nodes.size();i++){
            if(nodes[i].second<=final.back().second) continue;
            if(nodes[i].first<=final.back().second && nodes[i].second>final.back().second){
                final.back().second=nodes[i].second;
            } 
            else if(nodes[i].first>=final.back().second){
                final.push_back(nodes[i]);
            }
        }
        vector<int> size;
        for(int i=0;i<final.size();i++){
            size.push_back(final[i].second-final[i].first+1);
        }
        return size;
    }
};