class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long total=0;
        int n=nums.size();
        for(int i=0;i<k;i++) total+= 1LL * nums[n-1-i] * max(1,mul-i); 
        return total;
    }
};