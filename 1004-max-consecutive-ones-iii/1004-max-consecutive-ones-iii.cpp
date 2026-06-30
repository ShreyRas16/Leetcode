class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int size=0;
        int zero=0;
        vector<int> count;
        if(k!=0){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) size++;
            else{
                count.push_back(i);
                if(zero==k) {
                    size=count[count.size()-1]-count[0];
                    count.erase(count.begin());
                }
                else{
                    size++;
                    zero++;
                }
            }
            maxi=max(maxi,size);
        }
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(nums[i]==1) size++;
                else size=0;
                maxi=max(maxi,size);
            }
        }
        return maxi;
    }
};