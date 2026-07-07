class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int count=0;
        vector<int> temp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                if(cnt!=0){
                    temp.push_back(-cnt);
                    temp.push_back(nums[i]);
                    cnt=0;
                }
                else temp.push_back(nums[i]);
            }
            else cnt++;
        }
        if(cnt!=0) temp.push_back(-cnt);
        while(r<temp.size()){
            if(temp[r]%2>0) count++;
            while(count>k){
                if(temp[l]%2>0) count--;
                l++;
            }
            if(count==k && !(temp[r]>0 && r+1<(int)temp.size() && temp[r+1]<0)){
                if(temp[l]>0 && temp[r]>0) ans++;
                else if(temp[l]>0 && temp[r]<0) ans=ans+abs(temp[r])+1;
                else if(temp[l]<0 && temp[r]>0) ans=ans+abs(temp[l])+1;
                else ans=ans+((abs(temp[l])+1)*(abs(temp[r])+1));
            }
            r++;
        }
        return ans;
    }
};