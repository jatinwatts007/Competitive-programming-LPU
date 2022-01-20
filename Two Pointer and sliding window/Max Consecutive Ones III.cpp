class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int i=0,j=0;
        int ans=0;
        int count=0;
        while(j<nums.size()){
            if(nums[j]==1 && count<=k){
                j++;
            }else if(nums[j]==0 && count<k){
                count++;
                j++;
            }else if(count==k){
                if(j-i>ans) ans=j-i;
                while(nums[i]!=0)i++;
                i++;
                count--;
            }
        }
        if(count<=k && j-i>ans) ans =j-i;
        return ans;
    }
};
