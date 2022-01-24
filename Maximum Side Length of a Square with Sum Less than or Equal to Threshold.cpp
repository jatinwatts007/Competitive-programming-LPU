class Solution {
public:
    bool helper(vector<vector<int>>&ans,int &result,int mid,int target){
        int sum;
        for(int i=mid-1;i<ans.size();i++){
            for(int j=mid-1;j<ans[0].size();j++){
                if(j-mid>=0 && i-mid>=0){
                    sum=ans[i][j]-ans[i-mid][j]-ans[i][j-mid]+ans[i-mid][j-mid];
                }else if(j-mid>=0) sum=ans[i][j]-ans[i][j-mid];
                else if(i-mid>=0)sum=sum=ans[i][j]-ans[i-mid][j];
                else sum=ans[i][j];
                if(sum<=target){
                    result = mid;
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int target) {
        vector<int>temp(mat[0].size(),0);
        vector<vector<int>>v(mat.size(),temp);
        v[0][0]=mat[0][0];
        for(int i=1;i<mat.size();i++){
            v[i][0] = v[i-1][0]+mat[i][0];
        }
        for(int i=1;i<mat[0].size();i++){
            v[0][i] = v[0][i-1]+mat[0][i];
        }
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                v[i][j] = v[i-1][j]+v[i][j-1]-v[i-1][j-1]+mat[i][j];
            }
        }
        int l=1, r=min(mat.size(),mat[0].size());
        int result = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(helper(v,result,mid,target))l=mid+1;
            else r=mid-1;
        }
        return result;
    }
};
