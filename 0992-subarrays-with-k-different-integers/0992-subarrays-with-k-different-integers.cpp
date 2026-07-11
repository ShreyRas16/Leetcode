class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1=0;
        int l=0;
        int r=0;
        unordered_map<int,int> count;
        while(r<nums.size()){
            count[nums[r]]++;
            while(count.size()>k){
                count[nums[l]]--;
                if(count[nums[l]]==0) count.erase(nums[l]);
                l++;
            }
            ans1=ans1+r-l+1;
            r++;
        }
        count.clear();
        l=0;
        r=0;
        int ans2=0;
        while(r<nums.size()){
            count[nums[r]]++;
            while(count.size()>k-1){
                count[nums[l]]--;
                if(count[nums[l]]==0) count.erase(nums[l]);
                l++;
            }
            ans2=ans2+r-l+1;
            r++;
        }
        return ans1-ans2;
    }
};