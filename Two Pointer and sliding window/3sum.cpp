class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        if(nums.size()<=2) return v;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    v.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
                else if(sum>0) r--;
                else l++;
            }
        }
        return v;
    }
};
