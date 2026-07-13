class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> mp;
       for(int i=0;i<t.size();i++) mp[t[i]]++;
       unordered_map<char,int> temp;
       int l=0;
       int r=0;
       int best=s.size()+1;
       int fl=0;
       int match=0;
       bool update=false;
       if(s.size()<t.size()) return "";
       while(r<s.size()){
          if(mp.count(s[r])) {
            temp[s[r]]++;
            if(temp[s[r]]==mp[s[r]]) match++;
          }
            while(match==(int)mp.size()){
                if(r-l+1<best){
                    fl=l;
                    best=r-l+1;
                    update=true;
                }
                if(temp.count(s[l])){
                    if(temp[s[l]]==mp[s[l]]) match--;
                    if(temp[s[l]]==1) temp.erase(s[l]);
                    else if(temp[s[l]]>1) temp[s[l]]--;
                }
                l++;
            }
          r++;
       }
       if(!update) return "";
       return s.substr(fl,best);
    }
};