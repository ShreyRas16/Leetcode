class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        int j=0;
        int ans=0;
        for(int i=0;i<players.size();i++){
            while(j<trainers.size() && trainers[j]<players[i]) j++;
            if(j<trainers.size() && trainers[j]>=players[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};