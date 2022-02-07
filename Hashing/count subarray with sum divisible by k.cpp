class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] % k == 0)
            {
                count++;
            }
        }
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            int key;
            if(prefix[i] % k < 0)
            {
                key = (prefix[i] % k) + k;
            }
            else
            {
                key = prefix[i] % k;
            }
            count += m[key];
            m[key]++;
        }
        
        return count;
    }
};
