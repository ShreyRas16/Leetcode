class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1 || s.size()==0) return s.size();
        int ans=0;
        int size=0;
        unordered_map<char,int> mp;
        unordered_map<char,vector<int>> count;
        int start=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            count[s[i]].push_back(i);
            if(mp[s[i]]>1){
                if(count[s[i]][count[s[i]].size()-2]<start) size++;
                else{
                    start=count[s[i]][count[s[i]].size()-2]+1;
                    size=count[s[i]][count[s[i]].size()-1]-count[s[i]][count[s[i]].size()-2];
                    mp[s[i]]=1;
                }
            }
            else size++;
            ans=max(ans,size);
        }
        return ans;
    }
};