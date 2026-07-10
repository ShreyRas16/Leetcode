class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> nums;
        for(int i=0;i<k;i++) nums.push_back(cardPoints[i]);
        for(int i=cardPoints.size()-k;i<(int)cardPoints.size();i++) nums.push_back(cardPoints[i]);
        int l=0;
        int r=k-1;
        int sum=0;
        int total=0;
        for(int i=0;i<nums.size();i++) total=total+nums[i];
        for(int i=l;i<r+1;i++) sum=sum+nums[i];
        int maxi=0;
        while(l<nums.size()){
            if(l>r || l==0 || r==nums.size()-1) maxi=max(maxi,sum);
            sum=sum-nums[l];
            l++;
            r=(r+1)%nums.size();
            sum=sum+nums[r];
        }
        return maxi;
    }
};