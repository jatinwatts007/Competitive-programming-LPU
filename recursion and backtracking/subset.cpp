class Solution {
public:
    
    // this is storing all the generated subsets.
    vector<vector<int>> ans;
    
    // this basically includes all the numbers present in the generated subset.
    vector<int> present_set;
    
    void generateSet(int idx, vector<int>& nums) {
        
        // base condition
        if(idx==nums.size())    {
            ans.push_back(present_set);
            return;
        }
        
        //recursion
        
        // don't take present idx
        generateSet(idx+1, nums);
        
        // take present idx
        present_set.push_back(nums[idx]);
        generateSet(idx+1,nums);
        
        // going back up in the recursion, so update present_set.
        present_set.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        generateSet(0,nums);
        return ans;
    }
};
 
//The max no of operations can be upto 2^10 = 1024 amd the recursion depth is 10 at max
