class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        if(nums.size()==3) return max(nums[0],max(nums[1],nums[2]));
        if(nums.size()==4) return max(nums[nums.size()-1]+nums[1],nums[nums.size()-2]+nums[0]);
        int prev12=nums[nums.size()-3];
        int prev11=max(nums[nums.size()-4],nums[nums.size()-3]);
        int prev22=nums[nums.size()-2];
        int prev21=max(nums[nums.size()-3],nums[nums.size()-2]);
        for(int i=nums.size()-5;i>=1;i--){
            int curr1=max(nums[i]+prev12,prev11);
            prev12=prev11;
            prev11=curr1;
        }
        for(int i=nums.size()-4;i>=0;i--){
            int curr2=max(nums[i]+prev22,prev21);
            prev22=prev21;
            prev21=curr2;
        }
        return max(max(prev11,prev12)+nums[nums.size()-1],max(prev21,prev22));
    }
};