class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for(int l=0;l<s.size();l++){
            if(s[l]=='1') ones.push_back(l);
        }
        if(ones.size()<k) return "";
        if(k==1) return "1";
        int curri=0;
        int currj=0;
        int count=1;
        int finali=0;
        int finalj=0;
        int len=INT_MAX;
        while(curri<ones.size()-1 && currj<ones.size()-1){
            currj++;
            count++;
            if(count==k){
                if((ones[currj]-ones[curri]+1)<len || (ones[currj]-ones[curri]+1==len && s.substr(ones[curri],ones[curri]-ones[currj]+1)<s.substr(finali,len))){
                    len=ones[currj]-ones[curri]+1;
                    finali=ones[curri];
                    finalj=ones[currj];
                }
                curri++;
                count--;
            }
        }
        return s.substr(finali,finalj-finali+1);
    }
};