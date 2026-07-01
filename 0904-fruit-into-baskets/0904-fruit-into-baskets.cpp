class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int old;
        int nev;
        vector<int> arr;
        int ans=0;
        int f=0;
        for(int i=0;i<fruits.size();i++){
            if(arr.empty()){
                old=i;
                f++;
                arr.push_back(fruits[i]);
            }
            else if(arr.size()==1 && fruits[i]==arr[0]){
                f++;
                old=i;
            }
            else if(arr.size()==1 && fruits[i]!=arr[0]){
                nev=i;
                f++;
                arr.push_back(fruits[i]);
            }
            else if(arr.size()==2 && fruits[i]==arr[0]){
                arr[0]=arr[1];
                arr[1]=fruits[i];
                old=nev;
                nev=i;
                f++;
            }
            else if(arr.size()==2 && fruits[i]==arr[1]){
               nev=i; 
               f++;
            }
            else {
                f=i-old;
                if(arr[0]==fruits[old]){
                    arr[0]=arr[1];
                    arr[1]=fruits[i];
                }
                else if(arr[1]==fruits[old]) arr[1]=fruits[i];
                old=nev;
                nev=i;
            }
            ans=max(ans,f);
        }
        return ans;
    }
};