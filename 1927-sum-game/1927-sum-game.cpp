class Solution {
public:
    bool sumGame(string num) {
        int suml=0;
        int sumr=0;
        for(int i=0;i<num.size()/2;i++){
            if(num[i]!='?') suml=suml+(num[i]-'0');
            if(num[num.size()-i-1]!='?') sumr=sumr+(num[num.size()-i-1]-'0');
        }
        int countl=0;
        int countr=0;
        for(int i=0;i<num.size();i++){
            if(num[i]=='?'){
                if(i<num.size()/2) countl++;
                else countr++;
            }
        }
        if((countl+countr)%2!=0) return true;
        while(countl!=0 && countr!=0){
            suml=suml+9;
            countl--;
            sumr=sumr+9;
            countr--;
        }
        if(countl==0 && countr==0){
            if(suml==sumr) return false;
            else return true;
        }
        if(sumr>suml && countr>0) return true;
        if(suml>sumr && countl>0) return true;
        int diff=abs(sumr-suml);
        int alice=0;
        int bob=0;
        if(max(countr,countl)%2==0){
            alice=max(countr,countl)/2;
            bob=max(countr,countl)/2;
        }
        else if(max(countr,countl)%2==1){
            alice=max(countr,countl)/2;
            bob=max(countr,countl)/2+1;
        }
        if(diff>bob*9) return true;
        if(alice*9>diff) return true;
        return false;
    }
};