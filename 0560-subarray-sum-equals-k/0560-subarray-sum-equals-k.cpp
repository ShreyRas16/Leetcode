class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int pre=0;
        int ans=0;
        count[0]=1;
        for(int i=0;i<nums.size();i++){
            pre=pre+nums[i];
            ans=ans+count[pre-k];
            count[pre]++;
        }
        return ans;
    }
};