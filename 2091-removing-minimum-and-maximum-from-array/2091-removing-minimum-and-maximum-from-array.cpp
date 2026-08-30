class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minidx=0;
        int maxidx=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            if(maxi==nums[i]) maxidx=i;
            if(mini==nums[i]) minidx=i;
        }
        int n=nums.size();
        if(minidx==maxidx){
            int ansi=min(minidx+1,n-minidx);
            return ansi;
        }
        int ans=0;
        int minis=min(minidx+1,n-minidx);
        int maxis=min(maxidx+1,n-maxidx);
        if(minis>=maxis){
            ans=ans+maxis;
            if(maxis==maxidx+1){
                minis=min(minidx-maxidx,n-minidx);
                ans=ans+minis;
            }
            else{
                minis=min(maxidx-minidx,minidx+1);
                ans=ans+minis;
            }
        }
        else{
            ans=ans+minis;
            if(minis==minidx+1){
                maxis=min(maxidx-minidx,n-maxidx);
                ans=ans+maxis;
            }
            else{
                maxis=min(maxidx+1,minidx-maxidx);
                ans=ans+maxis;
            }
        }
        return ans;
    }
};