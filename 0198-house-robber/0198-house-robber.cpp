class Solution {
public:
    int find(int idx,vector<int>& dp,vector<int>& nums){
        if(idx>nums.size()-1) return 0;
        if(idx==nums.size()-1) return dp[nums.size()-1];
        if(idx==nums.size()-2) return dp[nums.size()-2];
        if(dp[idx]!=-1) return dp[idx];
        int maxi=INT_MIN;
        for(int i=idx+2;i<nums.size();i++){
            if(dp[i]==-1) find(i,dp,nums);
            maxi=max(maxi,dp[i]);
        }
        return dp[idx]=maxi+nums[idx];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1]=nums[nums.size()-1];
        dp[nums.size()-2]=nums[nums.size()-2];
        return max(find(0,dp,nums),find(1,dp,nums));
    }
};