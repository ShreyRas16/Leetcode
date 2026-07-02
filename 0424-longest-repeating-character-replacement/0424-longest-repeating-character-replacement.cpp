class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxf=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(r<s.size()){
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            if((r-l+1)-maxf > k){
                mp[s[l]-'A']--;
                l++;
            }
            else ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};