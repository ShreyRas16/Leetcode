class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        dp[nums.size()-1]=nums[nums.size()-1];
        dp[nums.size()-2]=max(nums[nums.size()-1],nums[nums.size()-2]);
        if(nums.size()==2) return max(dp[0],dp[1]);
        for(int i=nums.size()-3;i>=0;i--){
            dp[i]=max(dp[i+2]+nums[i],dp[i+1]);
        }
        return max(dp[0],dp[1]);
    }
};