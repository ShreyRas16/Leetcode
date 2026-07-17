class Solution {
public:
    bool checkValidString(string s) {
        vector<int> place;
        vector<int> p;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*') place.push_back(i);
            else if(s[i]=='(') p.push_back(i);
            else{
                if(!p.empty()) p.pop_back();
                else if(curr<place.size()) curr++;
                else return false;
            }
        }
        int currl=place.size()-1;
        int first=p.size()-1;
        while(first>=0 && currl>curr && place[currl]>p[first]){
            currl--;
            first--;
        }
        if(first>=0) return false;
        return true;
    }
};