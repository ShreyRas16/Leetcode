class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> nums=cardPoints;
        int l=0;
        int r=nums.size()-k-1;
        int sum=0;
        int total=0;
        for(int i=0;i<nums.size();i++) total=total+nums[i];
        for(int i=l;i<r+1;i++) sum=sum+nums[i];
        int mini=total;
        while(r<nums.size()-1){
            mini=min(mini,sum);
            sum=sum-nums[l];
            l++;
            r++;
            sum=sum+nums[r];
        }
        mini=min(mini,sum);
        return total-mini;
    }
};