class Solution {
public:
    bool checkDivisibility(int n) {
        int pro=1;
        int sum=0;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            pro=pro*(s[i]-'0');
            sum=sum+(s[i]-'0');
        }
        int final=pro+sum;
        if(n%final==0) return true;
        return false;
    }
};