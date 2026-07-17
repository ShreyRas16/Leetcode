class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(i>x) return false;
            x=max(x,i+nums[i]);
            if(x>=nums.size()) return true;
        }
        return true;
    }
};