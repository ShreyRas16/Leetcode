class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev2=nums[nums.size()-1];
        int prev1=max(nums[nums.size()-1],nums[nums.size()-2]);
        if(nums.size()==2) return max(prev2,prev1);
        for(int i=nums.size()-3;i>=0;i--){
            int curr=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=curr;
        }
        return max(prev2,prev1);
    }
};