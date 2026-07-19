class Solution {
public:
    int jump(vector<int>& nums) {
        int x=0;
        int step=0;
        int j=0;
        int k=nums[0];
        int y=0;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            x=max(x,i+nums[i]);
            if(i==k){
                step++;
                j=i;
                k=x;
            }
            if(k>=nums.size()-1){
                step++;
                return step;
            }
        }
        return step;
    }
};